Domain name system
==================================================

.. image:: images/DNS.jpg

DNS是分层的，顶层只有少量权威服务器。路由器或ISP提供DNS服务器信息。较低层的DNS服务器缓存域名-IP匹配信息，由于DNS传播延迟，这些缓存有可能是陈旧的。DNS查询结果也能被浏览器、操作系统缓存一段时间，由TTL(time to live)决定。以下是几种常见DNS记录：

- A记录(address)：又称IP指向，将域名指向IP地址。
- MX记录(mail exchange)：指定接收消息的邮件服务器。
- CNAME记录(canonical)：指向另外一个域名
- NS记录(name server)：域名服务器记录，用来表明由哪台服务器对该域名进行解析。例如用户希望由12.34.56.78这台服务器解析news.mydomain.com，则需要设置news.mydomain.com的NS记录。

Services such as CloudFlare and Route 53 provide managed DNS services. 一些DNS服务可用多种方式来路由流量：

- 带权重的轮流调度(Weighted round robin): http://g33kinfo.com/info/archives/2657
    - 阻止流量流向停机维护中的服务器
    - 在多个cluster大小间取得平衡
    - A/B测试
- 基于延迟的
- 基于地理位置的

缺点
----------------------------------
- 访问DNS服务器会有轻微的延迟，尽管可以用缓存来减轻
- DNS服务器的管理可能会很复杂，尽管通常是由政府、ISP、大公司管理的
- DNS服务经常遭到DDoS攻击。以twitter为例，尽管twitter的服务器正常运行，但负责解析其域名的DNS服务器却被攻击，导致用户无法从DNS服务器获得twitter服务器的IP，从而无法访问twitter。
