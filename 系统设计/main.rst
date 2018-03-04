Scalability
=================================================
Vertical scaling
-----------------------------------------
给单一结点增加或升级更多的资源，例如CPU、内存、磁盘。垂直扩展有极限，总有不能再升级的时候，单一机器的处理能力仍然是有限的。

Horizontal scaling
-----------------------------------------
增加更多的机器。

Proxy
-----------------------------------------

- A proxy server that passes unmodified requests and responses is usually called a gateway or sometimes a tunneling proxy.
- A forward proxy is an Internet-facing proxy used to retrieve from a wide range of sources (in most cases anywhere on the Internet).
- A reverse proxy is usually an internal-facing proxy used as a front-end to control and protect access to a server on a private network. A reverse proxy commonly also performs tasks such as load-balancing, authentication, decryption or caching.

Load balancing
-----------------------------------------

- DNS load balancing：给客户端返回不同的服务器IP

Session
-----------------------------------------
若某客户的session存放在单个服务器里，而load balancer给客户返回了另一个服务器的IP，那么用户就可能访问不到这些session，例如会被要求再次登录。

如何解决？可以：

- 用共享的磁盘，只用来存放session，所有服务器都可以访问它。(如果磁盘坏了就完了，不过可以使用RAID)
