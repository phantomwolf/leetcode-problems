#include <stdint.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define ADDR_BUF_SIZE 64
#define SOCK_BUF_SIZE 4096

int handler(int sockfd, const struct sockaddr* addr, socklen_t size)
{
	char addr_buf[ADDR_BUF_SIZE] = {0};
	char buf[SOCK_BUF_SIZE] = {0};
	int af;
	/* get ip address */
	if (size == sizeof(struct sockaddr_in)) {
		/* ipv4 */
		af = AF_INET;
	} else if (size == sizeof(struct sockaddr_in6)) {
		/* ipv6 */
		af = AF_INET6;
	} else {
		/* unknown address family */
		return -1;
	}
	if (NULL == inet_ntop(af, (const void*)addr, 
				addr_buf, size)) {
		perror("ERROR getting client ip address");
		return -1;
	}
	printf("%s: ", addr_buf);
	/* receive data */
	ssize_t n;
	do {
		n = recv(sockfd, buf, SOCK_BUF_SIZE, 0);
		if (n < 0) {
			fprintf(stderr, "%s: ERROR recv data\n", addr_buf);
			return -1;
		}
		fwrite((void*)buf, sizeof(char), n, stdout);
	} while (n == SOCK_BUF_SIZE);
	/* print data */
	/* shutdown for reading */
	if (shutdown(sockfd, SHUT_RD) < 0) {
		fprintf(stderr, "%s: ERROR shutdown for reading", addr_buf);
		return -1;
	}
	/* write string to buffer */
	snprintf(buf, SOCK_BUF_SIZE, "your ip is: %s\n", addr_buf);
	/* send data */
	ssize_t data_size = strlen(buf);
	ssize_t offset = 0;
	do {
		n = send(sockfd, (void*)buf + offset, data_size, 0);
		if (n < 0) {
			fprintf(stderr, "%s: ERROR shutdown for reading", 
								addr_buf);
			return -1;
		}
		offset += n;
	} while (offset < data_size);
	/* shutdown for writing */
	if (shutdown(sockfd, SHUT_WR) < 0) {
		fprintf(stderr, "%s: ERROR shutdown for writing", addr_buf);
		return -1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	int serv_sockfd;
	/* create socket for listening */
	serv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sockfd < 0) {
		perror("ERROR creating socket");
		exit(1);
	}
	/* set SO_REUSEADDR flag */
	int flag = 1;
	setsockopt(serv_sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
	/* create sockaddr structure */
	struct sockaddr_in serv_addr;
	uint16_t portno = 5001;
	memset((void*)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(portno);
	/* bind socket to host address */
	if (0 > bind(serv_sockfd, (const struct sockaddr*)&serv_addr,
						sizeof(serv_addr))) {
		perror("ERROR on binding");
		exit(1);
	}
	/* start listening */
	if (listen(serv_sockfd, SOMAXCONN) < 0) {
		perror("ERROR on listening");
		exit(1);
	}
	while(true) {
		/* accept connections */
		int cli_sockfd;
		struct sockaddr_in cli_addr;
		socklen_t cli_addr_len;
		cli_sockfd = accept(serv_sockfd, (struct sockaddr*)&cli_addr,
							&cli_addr_len);
		if (cli_sockfd < 0) {
			perror("ERROR accepting connections");
			exit(1);
		}
		/* fork and handle connection */
		pid_t pid = fork();
		if (!pid) {
			return handler(cli_sockfd,
					(struct sockaddr*)&cli_addr,
					sizeof(cli_addr));
		}
	}
	return 0;
}
