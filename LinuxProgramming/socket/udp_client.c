#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>                                                             
#include <stdio.h>                                                             
#include <stdlib.h>                                                            
#include <stdbool.h>                                                           
#include <stdint.h>                                                            
#include <string.h>
#include <sys/types.h>                                                         
#include <sys/socket.h>                                                        

#define SERVER_IP "127.0.0.1"
#define PORT 5001
#define BUF_SIZE 4096

int main(int argc, char** argv)
{
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Failed to create socket");
		exit(1);
	}

	struct sockaddr_in addr;
	uint32_t port = PORT;
	memset((void*)&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	/* send data */
	char buf[BUF_SIZE];
	size_t len;
	memset((void*)buf, 0, BUF_SIZE);
	snprintf(buf, BUF_SIZE, "Dota2 is good");
	len = sendto(sockfd, buf, strlen(buf), 0,
			(struct sockaddr*)&addr, sizeof(addr));
	printf("%d bytes sent", len);
	return 0;
}
