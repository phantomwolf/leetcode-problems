#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/types.h>
#define _GNU_SOURCE
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


#define SERVER_PORT 19527
#define MAX_EVENTS 10000
#define BACKLOG 100

#define BUF_SIZE 10


void set_nonblock(int fd)
{
    int opts = fcntl(fd, F_GETFD);
    if (opts < 0) {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, opts) < 0) {
        perror("fcntl(sock,SETFL,opts)");
        exit(2);
    }
}


void handle(int fd)
{
    int bytes;
    char buf[BUF_SIZE];
    FILE *fp = fdopen(fd, "r");
    bytes = fread(buf, sizeof(char), BUF_SIZE, fp);
    while (bytes > 0) {
        for (int i=0; i < bytes; ++i) {
            if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] -= 'a' - 'A';
            }
        }
        fwrite(buf, sizeof(char), bytes, stdout);
        if (bytes < BUF_SIZE) {
            break;
        }
    }
    close(fd);
}

int main(int argc, char *argv[])
{
    // Create address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Create server socket
    int listen_sock = socket(AF_INET,
                             SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC,
                             0);
    if (listen_sock == -1) {
        perror("Create socket failed");
        return -1;
    }

    // Bind
    if (bind(listen_sock,
             (const struct sockaddr *)&server_addr,
             sizeof(struct sockaddr_in)) == -1) {
        perror("Bind address failed");
        return -1;
    }

    // Listen
    if (listen(listen_sock, BACKLOG) == -1) {
        perror("Listen failed");
        return -1;
    }

    // Create epoll event
    int epfd = epoll_create1(EPOLL_CLOEXEC);

    // Register fd
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epfd,
                  EPOLL_CTL_ADD,
                  listen_sock,
                  &ev) == -1) {
        perror("epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev)");
        return -1;
    }
    // Accept connections
    struct epoll_event events[MAX_EVENTS];
    while (1) {
        struct sockaddr_in remote_addr;
        socklen_t addrlen = sizeof(struct sockaddr_in);

        int nfds = epoll_wait(epfd,
                              events,
                              MAX_EVENTS,
                              -1);
        if (nfds == -1) {
            perror("epoll_wait(epfd, events, MAX_EVENTS, -1)");
            return -1;
        }
        for (int i=0; i < nfds; ++i) {
            if (events[i].data.fd == listen_sock) {
                int connfd;
                while ((connfd = accept4(listen_sock, (struct sockaddr *)&remote_addr, &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC)) > 0) {
                    ev.events = EPOLLIN | EPOLLET;
                }
                ev.data.fd = connfd;
                if (epoll_ctl(epfd,
                              EPOLL_CTL_ADD,
                              connfd,
                              &ev) == -1) {
                    perror("epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev)");
                    return -1;
                }
                continue;
            } else {
                handle(events[i].data.fd);
            }
        }
    }
    return 0;
}
