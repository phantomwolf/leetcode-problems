#include "mystack.h"
#include <stdlib.h>
#include <string.h>

/* init a stack */
int mystack_init(struct mystack* stack)
{
	/* init mutex */
	pthread_mutexattr_t mutex_attr;
	pthread_mutexattr_init(&mutex_attr);
	/* enable recursive lock */
	pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&stack->mutex, &mutex_attr);
	pthread_mutexattr_destroy(&mutex_attr);
	/* alloc memory */
	stack->data = (void**)calloc(DEF_STACK_SIZE, sizeof(void*));
	stack->length = 0;
	stack->max_length = DEF_STACK_SIZE;
	return 0;
}

/* push data to stack */
int mystack_push(struct mystack* stack, void* data)
{
	/* realloc memory if necessary */
	if (stack->length == stack->max_length) {
		pthread_mutex_lock(&stack->mutex);
		stack->max_length += DEF_STACK_SIZE;
		stack->data = (void**)realloc(stack->data,
				sizeof(void*) * stack->max_length);
		/*memset(stack->data + stack->max_length - DEF_STACK_SIZE, 0, 
			sizeof(void*) * (stack->max_length - DEF_STACK_SIZE));*/
		pthread_mutex_unlock(&stack->mutex);
	}
	pthread_mutex_lock(&stack->mutex);
	stack->data[stack->length] = data;
	++stack->length;
	pthread_mutex_unlock(&stack->mutex);
	return 0;
}

/* pop data from stack */
int mystack_pop(struct mystack* stack, void** data)
{
	if (stack->length <= 0)	return 1;
	pthread_mutex_lock(&stack->mutex);
	--stack->length;
	(*data) = stack->data[stack->length];
	pthread_mutex_unlock(&stack->mutex);
	/* realloc memory if neccesary */
	if (stack->max_length > DEF_STACK_SIZE &&
		stack->length <= (stack->max_length - DEF_STACK_SIZE)) {
		pthread_mutex_lock(&stack->mutex);
		stack->max_length -= DEF_STACK_SIZE/2;
		stack->data = (void**)realloc(stack->data,
					sizeof(void*) * stack->max_length);
		pthread_mutex_unlock(&stack->mutex);
	}
	return 0;
}

/* destroy stack */
int mystack_destroy(struct mystack* stack)
{
	/* free data */
	for (int8_t i=0; i < stack->length; ++i) {
		free(stack->data[i]);
	}

	stack->length = 0;
	free(stack->data);
	stack->data = NULL;
	stack->max_length = 0;
	pthread_mutex_destroy(&stack->mutex);
	return 0;
}
