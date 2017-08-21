#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define FIFO_PATH "/tmp/example.fifo"


int main(int argc, char** argv)
{
	/* check if FIFO file exists */
	if (0 == access(FIFO_PATH, F_OK)) {
		if (0 != remove(FIFO_PATH)) {
			fprintf(stderr, "%s\n", strerror(errno));
			exit(255);
		}
	}
	/* create fifo file */
	if (0 != mkfifo(FIFO_PATH, S_IRUSR | S_IWUSR |
					S_IRGRP | S_IWGRP |
					S_IROTH | S_IWOTH)) {
		fprintf(stderr,
			"Failed to create FIFO file at %s\n", FIFO_PATH);
		exit(1);
	}
	/* fork */
	pid_t pid;
	pid = fork();
	if (-1 == pid) {
		fputs("fork failed\n", stderr);
		exit(2);
	} else if (0 == pid) {
		/* open FIFO file */
		FILE* fifo = fopen(FIFO_PATH, "rw");
		char buffer[512];
		/* child process */
		fgets(buffer, 512, fifo);
		printf("msg: %s\n", buffer);
	} else {
		/* open FIFO file */
		FILE* fifo = fopen(FIFO_PATH, "rw");
		/* parent process */
		fputs("parent: How do you do?\n", fifo);
	}
	return 0;
}
