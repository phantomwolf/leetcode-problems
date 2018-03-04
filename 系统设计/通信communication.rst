通信communicatoin
================================================

.. image:: images/communication.jpg

Hypertext transfer protocol (HTTP)
----------------------------------------
HTTP方法：

+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+
| Verb  | Description                                               | Idempotent*   | Safe  | Cacheable                                 |
+===================================================================+===============+=======+===========================================+
| GET   | Reads a resource                                          | Yes           | Yes   | Yes                                       |
+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+
| POST  | Creates a resource or trigger a process that handles data | No            | No    | Yes if response contains freshness info   |
+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+
| PUT   | Creates or replace a resource                             | Yes           | No    | No                                        |
+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+
| PATCH | Partially updates a resource                              | No            | No    | Yes if response contains freshness info   |
+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+
| DELETE| Deletes a resource                                        | Yes           | No    | No                                        |
+-------------------------------------------------------------------+---------------+-------+-------------------------------------------+

Idempotent表示可被重复调用多次，而结果不会不同。

TCP
----------------------------------------

UDP
----------------------------------------

Remote procedure call (RPC)
----------------------------------------
这里的RPC只一种设计方法。

.. image:: images/rpc.png

在RPC中，客户端引发一个过程在另一个地址空间中的调用(通常在服务器上)。RPC隐藏了如何与远程服务器交流的细节。常见的RPC协议有：Protobuf、Thrift、Avro。

RPC是一个request-response协议，它包含：

* Client program - Calls the client stub procedure. The parameters are pushed onto the stack like a local procedure call.
* Client stub procedure - Marshals (packs) procedure id and arguments into a request message.
* Client communication module - OS sends the message from the client to the server.
* Server communication module - OS passes the incoming packets to the server stub procedure.
* Server stub procedure - Unmarshalls the results, calls the server procedure matching the procedure id and passes the given arguments.
* The server response repeats the steps above in reverse order.

示例RPC调用::

    GET /someoperation?data=anId

    POST /anotheroperation
    {
        "data":"anId";
        "anotherdata": "another value"
    }

RPC的重点是向外部暴露“行为”。

RPC的缺点：

- RPC客户端与服务器实现高度耦合(因为客户端需要直接指明服务端上过程的名字)
- 调试困难

Representational state transfer (REST)
----------------------------------------
服务器向客户端提供一系列“资源”，客户端可以在这些“资源”上执行操作。所有通信都是无状态的，并且可以缓存。

RESTful接口有4种特质：

- Identify resources (URI in HTTP) - use the same URI regardless of any operation.
- Change with representations (Verbs in HTTP) - use verbs, headers, and body.
- Self-descriptive error message (status response in HTTP) - Use status codes, don't reinvent the wheel.
- HATEOAS (HTML interface for HTTP) - your web service should be fully accessible in a browser.

示例RESTful调用::

    GET /someresources/anId

    PUT /someresources/anId
    {"anotherdata": "another va lue"}

RESTful的重点是向外部暴露“资源”。它最小化了客户端与服务器之间的耦合度，常用于公开的HTTP API。REST uses a more generic and uniform method of exposing resources through URIs, representation through headers, and actions through verbs such as GET, POST, PUT, DELETE, and PATCH. Being stateless, REST is great for horizontal scaling and partitioning.

REST的缺点：

- 因为REST向用户暴露“资源”，所以如果“资源”并非自然组织的，就会有些困难。例如，过去一小时内更新过的记录中，与特定事件有关的，可能很难用一个path来表示，而是结合URP path、query parameter甚至request body来实现。
- REST依赖几个“动词”(GET, POST, PUT, DELETE, PATCH)，有些时候不符合你的要求。
- 获取包含嵌套关系的复杂资源，可能会要求客户端与服务器多次通信。
- 随着时间推移，API返回的回应中的字段可能会越来越多。尽管客户端不想要，还是得接收，导致了流量的增大。

RPC与REST的对比::

    Operation                           RPC                                         REST
    ---------------------------------   ---------------------------------------     -----------------
    Signup                              POST /signup                                POST /persons
    Resign                              POST /resign                                DELETE /persons/1234
                                        {
                                            "personid": "1234"
                                        }
    Read person                         GET /readPerson?personid=1234               GET /persons/1234
    Read person’s items                 GET /readUsersItemsList?personid=1234       GET /persons/1234/items
    Add item to person’s items          POST /addItemToUsersItemsList               POST /persons/1234/items
                                        {                                           {
                                            "personid": "1234";                         "itemid": "456"
                                            "itemid": "456"                         }
                                        }
    Update an item                      POST /modifyItem                            PUT /items/456
                                        {                                           {
                                            "itemid": "456";                            "key": "value"
                                            "key": "value"                          }
                                        }
    Delete an item                      POST /removeItem                            DELETE /items/456
                                        {
                                            "itemid": "456"
                                        }


