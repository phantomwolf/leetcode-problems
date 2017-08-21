#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv)
{
	/* pfd1: send data to child process */
	int pfd1[2];
	/* pfd2: read data from child process */
	int pfd2[2];
	pid_t pid;
	FILE* fp_read;
	FILE* fp_write;
	char buffer[512];
	int retval;
	/* create pipes */
	if (0 != pipe(pfd1) || 0 != pipe(pfd2)) {
		puts("Failed to create pipes");
		exit(1);
	}

	pid = fork();
	if (pid == -1) {
		puts("Failed to fork");
		exit(2);
	} else if (pid == 0) {
		/* child process */
		close(pfd1[1]);
		close(pfd2[0]);

		fp_read = fdopen(pfd1[0], "r");
		fp_write = fdopen(pfd2[1], "w");

		/* read data */
		if (NULL != fgets(buffer, 512, fp_read)) {
			printf("parent: %s", buffer);
		} else
			puts("Failed to read data from parent");
		/* write data */
		retval = fprintf(fp_write, "%s\n", "This is child speaking");
		if (0 > retval) {
			puts("Failed to write data to parent");
		}
		fflush(fp_write);
	} else {
		/* parrent process */
		close(pfd1[0]);
		close(pfd2[1]);

		fp_read = fdopen(pfd2[0], "r");
		fp_write = fdopen(pfd1[1], "w");

		/* write data */
		retval = fprintf(fp_write, "%s\n", "This is parent speaking");
		if (0 > retval) {
			puts("Failed to write data to child");
		}
		fflush(fp_write);
		/* read data */
		if (NULL != fgets(buffer, 512, fp_read)) {
			printf("child: %s", buffer);
		} else
			puts("Failed to read data from child");
	}
	/* close pipes */
	fclose(fp_read);
	fclose(fp_write);
	/* exit with 0 */
	return 0;
}
