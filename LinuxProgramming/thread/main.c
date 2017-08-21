#include "thread_pool.h"
#include <stdio.h>
#include <unistd.h>


void logger(char* msg, char* level)
{
    printf("[%s] %s\n", level, msg);
}

void logger_info(void* msg)
{
    logger((char*)msg, "INFO");
}

int main(int argc, char** argv)
{
    struct thread_pool pool;
    thread_pool_init(&pool, 4, 10);

    thread_pool_task_add(&pool, &logger_info,
			(void*)"Linux is good(from thread pool)");
    sleep(3);
    thread_pool_destroy(&pool);
    return 0;
}
