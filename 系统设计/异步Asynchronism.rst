异步Asynchronism
=========================================================
Asynchronous workflows help reduce request times for expensive operations that would otherwise be performed in-line. They can also help by doing time-consuming work in advance, such as periodic aggregation of data.

.. image:: images/asynchronism.png

消息队列
----------------------------------------
消息队列接受、保存、传递消息，适用于以下工作流程：

1. 应用将job提交到消息队列里，并将其状态通知给用户
2. 一个worker从消息队列获取job，处理它，并发出信号表明job已经完成

整个过程中，用户不会被阻塞，无需等待job的完成。

常见的消息队列：RabbitMQ、Amazon SQS

任务队列
----------------------------------------
任务队列接收任务和相关数据，并运行它们，最后传递结果。它们可以支持任务调度，可用于在后台运行计算密集的任务。常见的任务队列：Celery。

消息队列 vs 任务队列
----------------------------------------
消息队列只负责接收、传递消息，适合需要尽快处理的任务；任务队列则更像cron job，它接收、传递任务以及相关的数据，并处理任务，适合耗时较长的任务。

排气回压Back Pressure
----------------------------------------
若队列大小增长过于迅速，可能会导致队列大小大于内存大小，导致缓存缺失(cache miss)、磁盘读写、性能下降。Back Pressure可帮助限制队列的大小，因此保证队列中现有的任务拥有高吞吐量和响应时间：队列满了以后，客户端得到服务器返回的HTTP 503。客户端可以等待一会后重试(可以用Exponential backoff)。

缺点
----------------------------------------
简单的、不耗时的任务可以直接同步处理，用消息队列反而会增加延迟。
