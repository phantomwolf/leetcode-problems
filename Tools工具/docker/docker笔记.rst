准备知识
======================================================
术语
----------------------------------------
- image: 一个可执行的package，包含运行应用所需的所有东西：代码、运行时、库、环境变量、配置文件。
- container: 是image的一个运行实例。

与虚拟机的异同
----------------------------------------
container本地运行在linux上，并与其他container共享主机的内核。container运行一个单独的进程，与其它进程无异。而虚拟机则运行一个完整的guest操作系统，通过hypervisor来访问主机的资源。


使用Docker构建应用
======================================================
一个应用大致可分为3层：

- Stack：整个分布式系统，可包含多个service
- Services：分布式系统中的一个组件，例如5个apache实例(每个container一个实例)可以算一个service。
- Container：通常包含一个进程。

Container
----------------------------------------
用Dockerfile定义Container
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Dockerfile负责描述Container的内部环境，例如网络、磁盘等。

在一个单独的目录里创建一个Dockerfile::

    # Use an official Python runtime as a parent image
    FROM python:2.7-slim
    
    # Set the working directory to /app
    WORKDIR /app
    
    # Copy the current directory contents into the container at /app
    ADD . /app
    
    # Install any needed packages specified in requirements.txt
    RUN pip install --trusted-host pypi.python.org -r requirements.txt
    
    # Make port 80 available to the world outside this container
    EXPOSE 80
    
    # Define environment variable
    ENV NAME World
    
    # Run app.py when the container launches
    CMD ["python", "app.py"]

要使用代理，可以添加环境变量::

    # Set proxy server, replace host:port with values for your servers
    ENV http_proxy host:port
    ENV https_proxy host:port

一个简单的应用
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
在相同的目录里创建以下两个文件。

requirements.txt::

    Flask
    Redis

app.py::

    from flask import Flask
    from redis import Redis, RedisError
    import os
    import socket
    
    # Connect to Redis
    redis = Redis(host="redis", db=0, socket_connect_timeout=2, socket_timeout=2)
    
    app = Flask(__name__)
    
    @app.route("/")
    def hello():
        try:
            visits = redis.incr("counter")
        except RedisError:
            visits = "<i>cannot connect to Redis, counter disabled</i>"
    
        html = "<h3>Hello {name}!</h3>" \
               "<b>Hostname:</b> {hostname}<br/>" \
               "<b>Visits:</b> {visits}"
        return html.format(name=os.getenv("NAME", "world"), hostname=socket.gethostname(), visits=visits)
    
    if __name__ == "__main__":
        app.run(host='0.0.0.0', port=80)


Dockerfile中的"ADD . /app"命令，表示将当前目录的内容放入docker image中的/app目录，因此requirements.txt和app.py也会被放到docker image中的/app中。

构建docker image
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
使用以下命令构建docker image::

    docker build -t friendlyhello .

其中，-t选项设置image的tag，用docker image ls即可看到。

运行docker image
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
用以下命令运行docker image::

    docker run -d -p 4000:80 friendlyhello

由于Dockerfile中的“EXPOSE 80”语句，container的80端口将被暴露出来。默认情况下，container绑定到localhost(0.0.0.0)上。命令中的-p 4000:80表示将本机的4000端口影射到container的80端口。-d表示后台运行(daemon)。

开始运行后，访问localhost:4000，即可看到结果。

至此，我们就成功创建了一个docker container。


Service
----------------------------------------
分布式系统中，系统的不同组件称为service。service其实就是部署中的一个或多个相同的container，通过docker-compose.yml可以定义scale的数量，以及端口映射等。

docker-compose.yml
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
请看以下配置文件::

    version: "3"
    services:
      web:
        # replace username/repo:tag with your name and image details
        image: friendlyhello:latest
        deploy:
          replicas: 5
          resources:
            limits:
              cpus: "0.1"
              memory: 50M
          restart_policy:
            condition: on-failure
        ports:
          - "80:80"
        networks:
          - webnet
    networks:
      webnet:

以上配置文件的含义：

- version表示compose的版本
- 运行5个container，形成一个叫做"web"的service。限制每个container最多使用10%的CPU(横跨所有核心)和50MB内存
- 如果某个container崩溃，立刻重启
- 将主机的80端口映射到"web"的80端口
- 令"web"的所有container通过一个负载均衡网络"webnet"来共享80端口
- 使用默认设定定义"webnet"网络

运行该服务
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
首先，在主机上初始化一个集群(下一章会解释)::

    docker swarm init

接下来，运行你的service(命令创建了一个叫做"getstartedlab"的stack，下一章会介绍stack)::

    docker stack deploy -c docker-compose.yml getstartedlab

不出问题的话，我们的服务已经正常运行了。列出运行中的服务::

    docker service ls

可以看到service的名字为getstartedlab_web(stack名+service名)。查看运行中的container::

    docker container ls

可以看到有5个相同的container在运行。

不断用浏览器访问http://localhost ，会发现服务器的hostname经常变化，这是因为每个container都有一个不同的hostname，它们的hostname就是其ID，由于负载均衡采用round-robin算法，因此每次刷新页面都能访问到一个不同的container。
