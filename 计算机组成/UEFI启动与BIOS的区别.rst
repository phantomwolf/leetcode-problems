UEFI启动与BIOS的区别
===========================
EFI系统分区
-----------------------
EFI有一个EFI System Partition (ESP)分区，它只是一个用UEFI规范定义的FAT变种格式化过的分区而已，有一个特殊的GPT分区类型（以便帮助固件找到它）。它的作用是提供一个固件也可以访问的数据分区。每个EFI boot loader都存放在自己的子文件夹中（文件夹以操作系统的名字命名），这些子文件夹存放在ESP分区的EFI文件夹里。在linux系统上，ESP分区一般会被挂载到/boot/efi上。

EFI启动过程
----------------------
系统开启后，上电自检(POST)。之后加载UEFI固件，初始化一些硬件。固件读取Boot Manager数据，决定要启动那些UEFI应用和它们的位置，并启动它们。

EFI启动过程并不执行MBR中的代码，也不执行分区的boot sector(启动扇区，分区的0扇区)。EFI的闪存里存放了很多变量（键值对）。EFI读取自己的NVRAM（flash memory），找到BootOrder这个变量，例如：BootOrder: 0001,001A,0003(均为十六进制)。

找到后，遍历这个列表，去找对应的变量Boot####，如变量Boot0001，其值大概是这样一个路径：ACPI(a0341d0,0)PCI(1f,2)SATA(0,0,0)HD(1,800,64000,12029cda-8961-470d-82ba-aeb17dba91a5)File(\EFI\fedora\shim.efi)。另外，额外的参数也可以传递给这个要加载的程序。HD(1,800,64000,12029cda-8961-470d-82ba-aeb17dba91a5)表示要加载的程序位于：磁盘分区1，偏移量800，大小64000，分区的GUID。

值的注意的是，这个分区不需要是ESP分区，UEFI固件也不关心这个分区的GUID是否是ESP分区的标准GUID，只要分区的GUID与分区号匹配就行。唯一的要求是，这个分区必须使用FAT文件系统，因为这是UEFI固件唯一保证能访问的文件系统。

固件会按顺序将这个路径里尚未初始化的设备初始化。在上述路径中，ACPI、PCI很可能已经初始化完毕了。UEFI会将SATA设备初始化，之后查找HD()里描述的分区，找到后再去找文件：File(\EFI\fedora\shim.efi)。最终找到了要加载的程序。

如果出错，EFI会解析BootOrder中的下一个Boot####。

默认启动顺序
---------------------
如果BootOrder中的所有东西都失败了，UEFI固件会初始化所有外围设备，包括可移动设备。

EFI会优先从可移动设备（比如光驱、U盘）上寻找ESP分区，试图加载\EFI\BOOT\BOOTX64.EFI。

如果可移动设备上没有，则从固定的设备（比如硬盘）上做同样的事情。这就是EFI的默认行为。

默认启动下的行为
---------------------
以Fedora为例，Fedora使用shim工具。

默认启动时，固件启动File(\EFI\BOOT\BOOTX64.EFI)，其实它只是EFI/fedora/shim.efi的副本，但是行为稍微不同。

启动时，shim检查它自己是否是从\EFI\BOOT启动的。如果是，它检查同级目录下有没有fallback.efi。如果有，则将其作为普通的UEFI应用执行。

fallback.efi
--------------------
fallback.efi的作用是，启动一个操作系统或者维护工具（以便修复启动），也可能是操作系统安装程序。

当fallback.efi运行时，它遍历\EFI下的所有非Boot的目录，寻找BOOT.CSV。Fedora上有一个\EFI\fedora\BOOT.CSV，是个UCS-2编码的文件，每行都是一个启动路径::

	shim.efi,Fedora,,This is the boot entry for Fedora

对于BOOT.CSV中的任何一个有效元素，fallback.efi都会创建一个对应的Boot####变量，并将其加到BootOrder后面。在上例中，将要加入的是：File(\EFI\fedora\shim.efi)。

当fallback.efi处理好所有BOOT.CSV文件后，启动列表中第一项。下次启动时，我们就有正常的BootOrder可以用了。

    Astute readers will no doubt notice that often we have device paths with only the HD(1,800,64000,12029cda-8961-470d-82ba-aeb17dba91a5) and File(\EFI\fedora\shim.efi) components. The spec allows this explicitly, and in this case it initializes every peripheral in no particular order until it finds a partition matching that Hard Disk Media Device Path, and the appropriate file on it.↩

    In this case ACPI(a0341d0,0) represents the PCI Express Root Port on my CPU, and PCI(1f,2) is what lspci whould show as 00:1f.2 SATA controller: Intel Corporation 6 Series/C200 Series Chipset Family SATA AHCI Controller (rev 05).↩

    Yes, seriously, SATA(0,0,0) represents the disk and HD(1,800,64000,12029cda-8961-470d-82ba-aeb17dba91a5) represents the partition on it. I’m so sorry.↩

    Strictly speaking, the firmware is required to check one partition which has the correct GUID and label in GPT and is a FAT file system. It is allowed to check partitions without that GUID and label, but you can’t depend on it, and it is allowed to check other partitions that have file systems it understands, but you can’t depend on that either.↩

    Or whatever file name is appropriate on your architecture.↩

    I’m using backslashes for paths seen by code that’s running under UEFI, and forward slashes for code running under Linux, because that’s what those parts of the system typically use.↩


shim
-----------------
一个first stage boot loader，一个EFI应用。它运行时，试图打开并执行另一个程序（grub2）。首先它会试图用EFI的LoadImage()和StartImage()调用来达到目的，如果失败（例如secure boot已打开，且要执行的程序未用适当的key签名），它就用自己内置的key来验证那个程序。如果验证成功，且该程序和key不在黑名单里，shim会重定位并执行那个程序。

shim还实现了一个协议，允许second-stage bootloader来执行类似的验证。比如grub2会回调shim来验证kernel。
