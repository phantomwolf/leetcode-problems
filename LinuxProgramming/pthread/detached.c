#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct _thread_arg {
    int interval;
    int total;
};

typedef struct _thread_arg THREAD_ARG;

void *callback(void *arg)
{
    int secs, elapsed;
    THREAD_ARG *thread_arg = (THREAD_ARG *)arg;
    while (thread_arg->total > 0) {
        secs = sleep(thread_arg->interval);
        elapsed = thread_arg->interval - secs;
        thread_arg->total -= elapsed;
        printf("%us slept(%us remaining)\n",
                elapsed,
                thread_arg->total);
    }
    puts("Thread exiting...");
}


int main(int argc, char *argv[])
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;
    THREAD_ARG thread_arg;

    err = pthread_attr_init(&attr);
    if (err != 0) {
        printf("Failed to init thread attribute: %s\n", strerror(err));
        exit(err);
    }
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err != 0) {
        printf("Failed to set detach state: %s\n", strerror(err));
        exit(err);
    }
    thread_arg.interval = 30;
    thread_arg.total = 60;
    err = pthread_create(&tid, &attr, callback, &thread_arg);
    pthread_attr_destroy(&attr);
    if (err != 0) {
        printf("Failed to create thread: %s\n", strerror(err));
        exit(err);
    }
    sleep(thread_arg.total + 3);

    return 0;
}
