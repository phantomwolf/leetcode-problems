#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv)
{
	char buf[4096] = {'\0'};
	/* create sockepair */
	int sockets[2];
	if (0 != socketpair(AF_UNIX, SOCK_STREAM, 0, sockets)) {
		printf("%s\n", strerror(errno));
		exit(1);
	}
	/* fork */
	pid_t pid;
	pid = fork();
	if (pid) {
		close(sockets[1]);
		/* write to child */
		char* data = "parent speaking";
		if (strlen(data) != 
			write(sockets[0], (const void*)data, strlen(data))) {
			puts("parent: writing failed");
		}
		/* read from child */
		read(sockets[0], buf, 4096);
		printf("from child: %s\n", buf);
	} else {
		close(sockets[0]);
		/* read from parent */
		read(sockets[1], buf, 4096);
		printf("from parent: %s\n", buf);
		/* write to parent */
		char* data = "roger that!";
		if (strlen(data) != 
			write(sockets[1], (const void*)data, strlen(data))) {
			puts("child: writing failed");
		}
	}
	return 0;
}
