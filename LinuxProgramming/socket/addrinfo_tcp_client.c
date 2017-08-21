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
    struct addrinfo *results;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>", argv[0]);
        exit(255);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    int retval;
    retval = getaddrinfo(argv[1], argv[2], &hints, &results);
    if (retval != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        exit(1);
    }

    int sockfd;
    struct addrinfo* rp;
    for (rp = results; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;
        // connect
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;
        close(sockfd);
    }

    if (rp == NULL) {
        fprintf(stderr, "Unable to connect\n");
        exit(2);
    }

    char* data = "addrinfo client~~~";
    ssize_t nwrite;
    nwrite = write(sockfd, data, strlen(data));
    printf("%u bytes written to server\n", (unsigned int)nwrite);
    /* shutdown for writing */
    shutdown(sockfd, SHUT_WR);

    char buf[BUF_SIZE];
    ssize_t nread;
    memset(buf, 0, BUF_SIZE);
    nread = read(sockfd, buf, BUF_SIZE);
    printf("%u bytes read\nFrom server: %s\n", (unsigned int)nread, buf);
    shutdown(sockfd, SHUT_RD);

    return 0;
}
