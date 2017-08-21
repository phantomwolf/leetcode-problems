#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    int sockfd;
    uint16_t portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    /* process cmd arguments */
    if (argc != 3) {
        printf("Usage: %s <ip> <port>");
    }
    portno = atoi(argv[2]);
    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR on creating socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("ERROR on getting server hostent");
        exit(1);
    }
    memset((void*)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((void*)server->h_addr,
            (char*)&serv_addr.sin_addr.s_addr,
            server->h_length);
    serv_addr.sin_port = htons(portno);
    /* connect to the server */
    if (connect(sockfd, (const struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    /* write to server */
    char* msg = "Hi, here is Alice!\n";
    ssize_t n;
    n = write(sockfd, msg, strlen(msg));
    if (n < strlen(msg)) {
        perror("ERROR writing msg");
        exit(1);
    }
    /* read from server */
    char buf[256];
    memset((void*)buf, '\0', 256);
    do {
        n = read(sockfd, buf, 256);
        printf(">>> %s\n", buf);
    } while(n == 256);
    return 0;
}
