#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 180

int main()
{
    pid_t pid;
    char buf[MAXLINE];

    /* read from stdin */
    while (fgets(buf, MAXLINE, stdin)) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        if ((pid = fork()) < 0) {
        }
    }
}
