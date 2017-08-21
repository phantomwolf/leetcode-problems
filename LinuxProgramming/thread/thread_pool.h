#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

struct thread_pool_task {
    void (*func)(void*);
    void* arg;
};

struct thread_pool {
    pthread_t* thread_ids;
    int8_t pool_size;
    pthread_mutex_t mutex;
    struct thread_pool_task** tasks;
    int8_t max_task_count;
    bool enabled;
};

void do_nothing(void);
int thread_loop(struct thread_pool* pool);
int thread_pool_init(struct thread_pool* pool,
			int8_t size, int8_t max_task_count);
int thread_pool_task_add(struct thread_pool* pool,
			void (*func)(void*), void* arg);
int thread_pool_destroy(struct thread_pool* pool);
