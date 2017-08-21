#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 5001
#define BUF_SIZE 4096

int main(int argc, char** argv)
{
	/* create socket */
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Failed to create socket");
		exit(1);
	}
	/* create sockaddr_in */
	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	memset((void*)&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	/* bind socket to addr */
	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("Failed to bind");
		exit(2);
	}
	/* receive datagram */
	while (true) {
		char buf[BUF_SIZE];
		size_t len;
		memset((void*)buf, 0, BUF_SIZE);
		len = recvfrom(sockfd, buf, BUF_SIZE, 0,
				(struct sockaddr*)&addr, &addr_len);
		fputs("client: ", stdout);
		fwrite((void*)buf, sizeof(char), len, stdout);
		fputs("\n", stdout);
	}
}
