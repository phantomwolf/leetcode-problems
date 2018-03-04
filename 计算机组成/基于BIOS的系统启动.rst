基于BIOS的系统启动
==============================
系统启动的流程大致如下

.. image:: images/Overview.gif

固件阶段
-----------------

- 主板供电，加载固件，启动CPU。
- CPU启动时，有一个核心被选为Bootstrap Processor(BSP)，这一过程是动态的；其它核心被称为Application Processor(AP)，挂起直到内核激活他们。
- Bootstrap Processor执行位于Reset vector(FFFFFFF0h, 4GB向下16字节)的指令，这条指令必须是jump，跳转到BIOS入口处。须知这里用到了memory-mapped I/O，reset vector和BIOS并不真的在RAM里，而是位于闪存，这些物理地址被映射到了闪存中。

BIOS在执行过程中，可能会把自己从闪存里复制到RAM中，以获得更快的访问速度。这叫作BIOS shadowing。

- BIOS上电自检(POST)，例如检查显卡、键盘，并初始化：中断，内存范围，I/O端口（PCI设备），ACPI数据表。BIOS分为两部分：POST和runtime service。POST完成后被移出内存；而runtime service则留在内存里。
- BIOS查询CMOS里的设置，按顺序寻找操作系统：硬盘上，光驱上，软盘上，等等。

引导程序
-----------------
假定从硬盘启动

- BIOS读取硬盘的MBR，将其装载到0x7c00，并将控制权交给它

MBR是Master Boot Record，硬盘的0扇区，即前512字节，包含引导程序(446字节)、分区表(64字节)。在grub里，MBR里的引导程序称为stage 1(boot.img)。

对于Windows，stage 1引导程序会寻找唯一一个标记为active的分区，将该分区的boot sector/boot record/第一个扇区加载到RAM并执行。但grub可以从非active的分区启动，且可以识别一些linux文件系统(不像LILO那样直接读磁盘扇区，而是靠文件路径来寻找kernel)。

- stage 1太小，不能理解文件系统，无法直接加载位于/boot/grub下的stage 2内容。于是stage 1先加载stage 1.5(core.img)，一般存放在MBR与第一个分区之间的空闲扇区。它的功能是加载配置文件和所需模块（尤其是文件系统驱动）。
- 有了stage 1.5的帮助，grub可以识别文件系统了。于是加载/boot/grub下的stage 2到RAM。
- stage 2加载后，grub显示启动菜单，列出可用的kernel，还允许用户修改参数。stage 2加载kernel image和initrd到RAM，并将控制权转交给kernel。

kernel image分为两部分，实模式内核和其它部分，前者被装载到实模式下仅有的640K RAM里，后者装载到RAM中第1个MB之后。为了访问超过1MB的内存，装载过程中，CPU会在实模式和保护模式之间切换。

实模式内核阶段
-----------------

- 跳转到实模式内核执行，进行一些初始化后，调用go_to_protected_mode()，创建临时GDT和IDT。最终protected_mode_jump()在CPU的CR0寄存器上设置PE位，进入保护模式，可以访问1MB以上的内存了。
- 执行start_32()，调用decompress_kernel()将kernel image的剩余部分解压缩到高位地址。如果存在initrd，此例程将initrd加载到内存，以备使用。

保护模式内核
----------------

- 保护模式内核里也有个startup_32函数(也叫swapper或process 0)。调用它，将创建好最终的GDT、IDT、页表，并开启内存分页。
- 调用start_kernel()，会设置中断、内存，各个内核子系统，加载initial RAM disk。函数的最后，调用kernel_thread创建一个以init函数为入口的内核进程，即process 1。
- 最终调用cpu_idle()启动idle task，调度器接过控制权。

在内核启动过程中，被stage 2引导程序加载到memory的initrd，被复制到RAM并挂载。initrd作为一个临时的root文件系统，允许内核完全启动而不需要挂载物理磁盘。且initrd中可能包含访问外围设备所需的模块，例如文件系统模块。这也让kernel的体积变得很小。kernel启动后，initrd被卸载，真正的root被挂载。
