#include <pthread.h>


#define DEF_STACK_SIZE 64

struct mystack {
    void** data;
    size_t length;
    size_t max_length;
    pthread_mutex_t mutex;
};

int mystack_init(struct mystack* stack);
int mystack_push(struct mystack* stack, void* data);
int mystack_pop(struct mystack* stack, void** data);
int mystack_destroy(struct mystack* stack);
