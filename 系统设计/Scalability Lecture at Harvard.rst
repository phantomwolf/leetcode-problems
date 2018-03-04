Web Hosts
=================================================
What features should you be looking for from a web hosting company?

- Block ip ranges, like a country or specific websites(like youtube, facebook)
- sftp
- Encryption, like HTTP over SSL/TLS.
- Username & Password

VPS(Virtual Private Server)
=================================================
VPS provides you with a virtual machine, while web hosts only provides (apache) virtual hosts.

Vertical scaling
=================================================
纵向扩展(垂直扩展)，是从单机的角度通过增加硬件处理能力，比如CPU处理能力，内存容量，磁盘等方面，实现服务器处理能力的提升，不能满足大型分布式系统（网站），大流量，高并发，海量数据的问题。

垂直扩展并不是一个完整的方案，因为单一结点的升级是有限的，性能不可能一直提升。

现在的硬件性能很高，我们得想办法如何利用它们。于是我们在强大的电脑上建立虚拟机，将一台服务器分割成多台，向很多人提供服务。

磁盘技术：PATA、SATA、SAS(Serial Attached SCSI，每秒上万转)、SSD

Horizontal scaling
=================================================
No ceiling. 用一群较便宜的硬件来组成集群，将用户的请求分发到这些机器。


Session的存储
=================================================
若Session(例如登录信息、购物车里的内容等)分别存放在每个服务器上，那如果用户第一次被分配到了A服务器，登录后，又被分配到了B服务器上，这时就得重新登录，购物车信息也会丢失，这是不可接受的。所以我们可以将session存放到一个集中的地方。

可能的解决方案：可以准备一个外部存储磁盘，与集群里的所有服务器连接(比如iSCSI、nfs等)，每当一个服务器要存储session时，都存放到这个共享存储里(如果这磁盘坏了就全完了，可以用RAID来增加一些redundancy)；把session存放到load balancer那台机器上，所有服务器存储/加载session时都通过load balancer机器(单点故障)；也可以将session存到数据库中，但如果数据库服务器崩溃，整个系统也就无法运行了，所以还需要对数据库做HA。

虽然RAID提供了相当的redundancy，但如果停电也就停止工作了，所以有的服务器有多个电源供应，还可以加个UPS。不过如果所有电源供应都失效了，RAID还是会停止工作。

如果使用一个Shared Storage(共享存储)来存储session，那么可以用FC(Fiber Channel，用于快速在服务器间交换数据)、iSCSI(通过ip协议共享SCSI设备，较便宜)、数据库、nfs等等。

Sticky Session
-----------------------------------------
Sticky Session，能让你尽管多次访问一个网站，却总能使用同一个session object。一种方法是：使用Sticky Session(粘性会话, 会话关联)功能，可以使load balancer(负载均衡器)将用户绑定到特定的服务器实例上，确保会话期间用户的所有请求均发送到相同的服务器实例中。这就保证了服务器上总是有该用户的session信息(例如登录信息、购物车内容)。

将session里的所有信息都存入cookie，会有严重的安全、隐私问题，因为cookie一般是明文存储，如果把诸如用户名、密码之类的信息都存到cookie里会很危险。cookie里一般只存用户名、session id之类的信息。


Load Balancing负载均衡
=================================================
负载平衡（Load balancing）是一种计算机网络技术，用来在多个计算机（计算机集群）、网络连接、CPU、磁盘驱动器或其他资源中分配负载，以达到最优化资源使用、最大化吞吐率、最小化响应时间、同时避免过载的目的。

负载均衡的作用（解决的问题）：

1. 解决并发压力，提高应用处理性能（增加吞吐量，加强网络处理能力）；
2. 提供故障转移，实现高可用；
3. 通过添加或减少服务器数量，提供网站伸缩性（扩展性）；
4. 安全防护；（负载均衡设备上做一些过滤，黑白名单等处理）

Increased Scalability
	If you have a website, you must be uploading engaging content to attract readers. And it must be exciting to see a growing number of visitors on your site. However, it is important to remember that the amount of traffic on the website has a direct effect on the performance of the website. If there is a sudden spike in the traffic, it might become difficult for your server to handle the excess traffic and the website may crash. By introducing load balancing, the traffic can be spread across multiple servers and the increase in the traffic can be handled in a much easier manner. Depending on how the site’s traffic fluctuates, the server administrators can scale the web servers up or down depending upon your site’s needs.

Redundancy
	When you use load balancing for maintaining a website on more than one web server, the impact of hardware failure on a site’s overall uptime can be limited significantly. By implementing load balancing you can achieve redundancy. This means that when the website traffic is sent to two or more web servers and one server fails, then the load balancer will automatically transfer the traffic to the other working servers. When you maintain multiple load balanced servers, you can be assured that a working server will always be online to handle site traffic even when the hardware fails.

Reduced Downtime, Increased Performance
	If your company is located in just one place, then you can schedule the maintenance and planned downtime at non-working hours like early mornings or the weekends. However, if you have a global business with offices scattered across the world, with different time-zones, you need to implement load balancing. This will enable you to shut off any server for maintenance and channel traffic to your other resources without disrupting work in any location. This way you can reduce the downtime, maintain the uptime and improve the performance.

Efficiently Manages Failures
	Load balancing helps in detecting failures early on and manages them efficiently, making sure that failure of any kind doesn’t affect the servers or the workload. By using multiple data centers that are spread across a number of cloud providers, you can bypass the detected failures by re-distributing resources to other areas that are unaffected, thus causing minimal disruption.

Increased Flexibility
	IT administrators can enjoy great flexibility in handling website traffic by using multiple load balanced servers. They can perform several maintenance tasks on the server without impacting the site’s uptime. This is achieved by directing all the traffic to one server and putting the load balancer in active/passive mode. You have the flexibility of having a staggered maintenance system, where at least one server is always available to pick up the workload while others are undergoing maintenance. This ensures that the site’s users do not experience any outages at any time.


软件负载均衡器：ELB、HAProxy、LVS；硬件负载均衡器：Barracuda、Cisco、Citrix、F5。


DNS负载均衡
--------------------------------------
最早的负载均衡技术，利用域名解析实现负载均衡，在DNS服务器，配置多个A记录，这些A记录对应的服务器构成集群。大型网站总是部分使用DNS解析，作为第一级负载均衡。如下图：

.. image:: images/dns-load-balancing.png

优点：

- 使用简单：负载均衡工作，交给DNS服务器处理，省掉了负载均衡服务器维护的麻烦
- 提高性能：可以支持基于地址的域名解析，解析成距离用户最近的服务器地址，可以加快访问速度，改善性能；

缺点：

- 可用性差：DNS解析是多级解析，新增/修改DNS后，解析时间较长；解析过程中，用户访问网站将失败；
- 扩展性低：DNS负载均衡的控制权在域名商那里，无法对其做更多的改善和扩展；
- 维护性差：也不能反映服务器的当前运行状态；支持的算法少；不能区分服务器的差异（不能根据系统与服务的状态来判断负载）

实践建议：将DNS作为第一级负载均衡，A记录对应着内部负载均衡的IP地址，通过内部负载均衡将请求分发到真实的Web服务器上。一般用于互联网公司，复杂的业务系统不合适使用。如下图：

.. image:: images/recommended-dns-load-balancing.png

IP负载均衡
--------------------------------------
在网络层通过修改请求目标地址进行负载均衡。用户请求数据包，到达负载均衡服务器后，负载均衡服务器在操作系统内核进程获取网络数据包，根据负载均衡算法得到一台真实服务器地址，然后将请求目的地址修改为，获得的真实ip地址，不需要经过用户进程处理。真实服务器处理完成后，响应数据包回到负载均衡服务器，负载均衡服务器，再将数据包源地址修改为自身的ip地址，发送给用户浏览器。如下图：

.. image:: images/ip-load-balancing.png

IP负载均衡，真实物理服务器返回给负载均衡服务器，存在两种方式：（1）负载均衡服务器在修改目的ip地址的同时修改源地址。将数据包源地址设为自身盘，即源地址转换（snat）。（2）将负载均衡服务器同时作为真实物理服务器集群的网关服务器。

优点：

- 在内核进程完成数据分发，比在应用层分发性能更好；

缺点：

- 所有请求响应都需要经过负载均衡服务器，集群最大吞吐量受限于负载均衡服务器网卡带宽；

链路层负载均衡
--------------------------------------
在通信协议的数据链路层修改mac地址，进行负载均衡。数据分发时，不修改ip地址，指修改目标mac地址，配置真实物理服务器集群所有机器虚拟ip和负载均衡服务器ip地址一致，达到不修改数据包的源地址和目标地址，进行数据分发的目的。实际处理服务器ip和数据请求目的ip一致，不需要经过负载均衡服务器进行地址转换，可将响应数据包直接返回给用户浏览器，避免负载均衡服务器网卡带宽成为瓶颈。也称为直接路由模式（DR模式）。如下图：

.. image:: images/DR-load-balancing.png

优点：性能好；

缺点：配置复杂；

实践建议：DR模式是目前使用最广泛的一种负载均衡方式。

混合型负载均衡
--------------------------------------
由于多个服务器群内硬件设备、各自的规模、提供的服务等的差异，可以考虑给每个服务器群采用最合适的负载均衡方式，然后又在这多个服务器群间再一次负载均衡或群集起来以一个整体向外界提供服务（即把这多个服务器群当做一个新的服务器群），从而达到最佳的性能。将这种方式称之为混合型负载均衡。

此种方式有时也用于单台均衡设备的性能不能满足大量连接请求的情况下。是目前大型互联网公司，普遍使用的方式。

方式一，如下图：

.. image:: images/mixed-mode1.png

以上模式适合有动静分离的场景，反向代理服务器（集群）可以起到缓存和动态请求分发的作用，当时静态资源缓存在代理服务器时，则直接返回到浏览器。如果动态页面则请求后面的应用负载均衡（应用集群）。

方式二，如下图：

.. image:: images/mixed-mode2.png

以上模式，适合动态请求场景。

因混合模式，可以根据具体场景，灵活搭配各种方式，以上两种方式仅供参考。


PHP加速
=================================================
- Code Optimization
- PHP OpCode
- PHP Accelerator(like Zend)


Caching
=================================================
- 将频繁访问而内容不变的页面，生成为静态html页面。比如一篇新闻文章，一个FAQ页面。优点：速度快；缺点：如果这些页面需要修改，那么就必须重新生成所有html页面。
- MySQL Query Cache。
- memcached: memory cache. 在内存里保存key-value对。比如可以存储SQL查询的结果。LRU算法。


Database Replication
=================================================
最简单的结构：一个master对应多个slave。slave与master中的数据完全相同。适用于大量读操作的服务器。slave只能读，master可以读写。

为此，可以引入多个master，然后每个master有自己的若干slave。与上一个类似，但写操作可以在任意一个master上进行。如果对其中一个master进行写操作，那么同样的操作也将在其他master上进行。
