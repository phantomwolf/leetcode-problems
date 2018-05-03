# epoll简介
## 传统的select和poll
select和poll都可以监视多个文件描述符(file descriptor)，保持阻塞，直到它们可读/写为止。

两者的区别是，select只能监视有限数量的fd(FD_SETSIZE被hardcode为1024)。而poll接受一系列pollfd，没有这个限制。

## epoll
epoll与poll的功能相似，但性能要高很多。

### 使用方法

