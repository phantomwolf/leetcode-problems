Unified Extensible Firmware Interface(UEFI)
======================================================
UEFI是一套规范，它定义了操作系统与固件之间的一个软件接口。UEFI替代了BIOS，但大多数UEFI固件都兼容BIOS功能。

优点
---------------------

- 能从GPT分区表的、超过2TB的大磁盘上启动
- 独立于CPU的架构
- 独立于CPU的驱动
- 灵活的前操作系统环境，包括网络能力
- 模块化设计
- 像前、像后兼容

特性
---------------------
服务
~~~~~~~~~~~~~~
EFI定义了两种服务：启动服务(boot services)、运行时服务(runtime services)。启动服务仅当固件拥有控制权时才可用（在调用ExitBootServices之前），例如字符/图形终端、总线/块设备/文件服务；运行时服务在操作系统运行时仍然可用，例如日期、时间、NVRAM访问。

变量服务
+++++++++++
UEFI变量提供了一种在固件与操作系统或UEFI应用之间分享数据的方法。变量命名空间是由GUID标识的，变量都是键值对。比如，变量可以在NVRAM中存储崩溃信息，以便操作系统重启后可以获取它。

时间服务
+++++++++++
UEFI提供独立于设备的时间服务，支持时区、夏令时，允许硬件时间被设置为UTC或localtime。

应用
~~~~~~~~~~~~~~
UEFI可以运行UEFI应用，它们作为文件存放在EFI系统分区上，可以被UEFI shell、固件的boot manager、其他UEFI应用来执行。

有一类UEFI应用叫做操作系统加载器（OS loader），例如Grub、Windows Boot Manager。它们将操作系统文件加载到内存中并执行；也能提供用户界面，允许用户选择要执行的另一个UEFI应用。UEFI shell也是UEFI应用。

协议
~~~~~~~~~~~~~~
EFI定义了一系列软件接口，作为两个二进制模块相互通信的协议。所有EFI驱动必须通过协议对其它驱动提供服务。

设备驱动
~~~~~~~~~~~~~~
除了传统的特定处理器架构的驱动外，EFI还提供了独立于处理器架构的设备驱动，它们用EFI字节码或EBC写成。系统固件有EBC镜像解释器。

图形特性
~~~~~~~~~~~~~~
EFI定义了一个UGA (Universal Graphic Adapter)协议。UEFI用GOP (Graphics Output Protocol)协议替换了它。

EFI系统分区
~~~~~~~~~~~~~~
EFI System partition, ESP. 当电脑启动时，UEFI固件加载ESP分区上的文件，来启动已经安装好的操作系统和其他工具。

ESP分区需要被格式化为FAT文件系统，但是这个文件系统是由UEFI的规范定义的，因此与原来的FAT文件系统是独立的（将来有可能会与原本的FAT不同）。ESP分区在GPT分区表里的GUID是C12A7328-F81F-11D2-BA4B-00A0C93EC93B；MBR中，ESP分区的类型为0xEF。MBR、GPT分区的磁盘都可以包含ESP分区，因为UEFI固件被要求支持这两种分区方式。

UEFI提供向后兼容，它保留了分区的第一个扇区作为boot sector。在基于BIOS的系统上，分区的第一个扇区被加载到内存中并跳转执行（Windows）。除非通过CSM(Compatibility Support Module)以BIOS模式启动，UEFI并不会执行boot sector的代码。

启动
~~~~~~~~~~~~~~
UEFI启动
+++++++++++++
UEFI规范中定义了boot manager，而不是像BIOS那样依赖boot sector。电脑开机后，boot manager检查