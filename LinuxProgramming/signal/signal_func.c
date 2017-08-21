#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/*#define _XOPEN_SOURCE >= 700 || _POSIX_C_SOURCE >= 200809L*/
#define _GNU_SOURCE
/*char *strsignal(int sig);
extern const char * const sys_siglist[];*/

void handler(int signo)
{
    printf("signal: %s\n", strsignal(signo));
    exit(signo);
}

int main(int argc, char** argv)
{
    signal(SIGALRM, handler);
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    alarm(10);
    pause();
    return 0;
}
