#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    struct addrinfo hints;
    struct addrinfo *result;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = 0;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    int retcode;
    if ((retcode = getaddrinfo(NULL, argv[1], &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retcode));
        exit(2);
    }
    /* bind address */
    struct addrinfo* rp;
    int sockfd;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype,
                                        rp->ai_protocol);
        if (sockfd == -1)
            continue;
        if (bind(sockfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;
    }
    /* listen */
    if (listen(sockfd, SOMAXCONN) != 0) {
        fprintf(stderr, "Failed to start listening\n");
        exit(3);
    }
    int fd;
    ssize_t n, sum;
    char buf[BUF_SIZE];
    while (true) {
        /* accept connections */
        fd = accept(sockfd, rp->ai_addr, &rp->ai_addrlen);
        sum = 0;
        /* read data */
        do {
            n = read(fd, buf, BUF_SIZE);
            sum += n;
            fwrite(buf, sizeof(char), n, stdout);
        } while (n == BUF_SIZE);
        shutdown(fd, SHUT_RD);
        /* write data */
        snprintf(buf, BUF_SIZE, "received %d bytes", sum);
        write(fd, buf, strlen(buf));
        shutdown(fd, SHUT_WR);
    }
    return 0;
}
