Multicast多播
=========================================================
多播（英语：multicast，台湾又译作多点发送、多点广播或群播，中国大陆又译作组播）是指把信息同时传递给一组目的地址。它使用的策略是最高效的，因为消息在每条网络链路上只需传递一次，且只有在链路分叉的时候，消息才会被复制。与多播相比，常规的点到单点传递被称作单播。当以单播的形式把消息传递给多个接收方时，必须向每个接收者都发送一份数据副本。由此产生的多余副本将导致发送方效率低下，且缺乏可扩展性。

多播有应用层多播(application layer multicast)，也有网络协助的多播(network assisted multicast)，后者使通过一次传输就把数据发送给一组目标成为可能。链路层多播有Ethernet multicast addressing, Asynchronous Transfer Mode (ATM), point-to-multipoint virtual circuits (P2MP) or Infiniband。此外还有IP层的IP多播。

IP多播是一种用一次传输就把IP数据包发给一组感兴趣的接收者的方法，它使用保留的多播地址。涉及IP多播的协议有：Internet Group Management Protocol, Protocol Independent Multicast and Multicast VLAN Registration. IGMP snooping。


Virtual Router Redundancy Protocol
=========================================================
虚拟路由器备援协定Virtual Router Redundancy Protocol (VRRP)是一个电脑网络协议，它将IP路由器自动分配给参与的主机。提高了可用性和可靠性。Keepalived就使用此协议。

原理是，创建一些虚拟路由器，它们是多个路由器(主路由器、备份路由器)的抽象表现。主机们的默认网关被设置为虚拟路由器，若代表虚拟路由器转发包的物理路由器故障，另一个物理路由器会自动被选出来替代它。任何时候，转发包的物理路由器被叫做主路由器(master router)。

虚拟路由器必须使用这样的MAC地址：00-00-5E-00-01-XX。XX为虚拟路由标识符(Virtual Router IDentifier, VRID)，网络中每个虚拟路由的VRID都不同。此MAC地址同一时间只被一个物理路由使用，针对虚拟路由IP地址的ARP请求会返回此MAC地址。虚拟路由中的物理路由们只能通过多播IP地址224.0.0.18和112号IP协议与其本身通信。

路由器有1-254的优先级，优先级最高的会称为主路由器(master)。

主路由器的选举
----------------------------------------------
如果经过了3倍的advertisement timer的时间还没从主路由器收到多播包，备份路由器就认为主路由器已死。虚拟路由器就进入不稳定状态，并进行选举，来从备份路由器中选出新的主路由器。这是通过使用多播包来实现的。

备份路由器仅能在选举中发送多播包（除非某物理路由器优先级比当前主路由器高，它将会抢占主路由器）。优先级最高的路由器，将自己的优先级设置的比当前的主路由器还高，从而成为新的主路由器。之后，它就会负责将发送给该MAC地址的包进行路由(若所有备路由器优先级都相同，IP地址最高的一个会被选中)。

虚拟路由中的所有路由器必须属于同一个LAN。虚拟路由内部的通信会定期进行，可通过设置advertisement interval timers来调整。advertisement interval越短，黑洞期(输入输出流量均被悄悄废弃，并不通知包的来源)越短，但网络中的流量也会更多。
