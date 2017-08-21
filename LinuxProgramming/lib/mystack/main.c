#include "mystack.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct data {
	int8_t num;
};


int main(int argc, char** argv)
{
	int retval;
	struct data* ptr;
	struct mystack stack;
	mystack_init(&stack);
	for (int8_t i=0; i <= 50; ++i) {
		/* create data */
		ptr = (struct data*)malloc(sizeof(struct data));
		memset((void*)ptr, 0, sizeof(struct data));
		ptr->num = i;
		/* push to stack */
		retval = mystack_push(&stack, (void*)ptr);
		if(retval != 0)
			puts("Failed to push data to stack");
	}
	for (int8_t i=0; i <= 20; ++i) {
		/* pop data */
		retval = mystack_pop(&stack, (void**)&ptr);
		if(retval != 0)
			puts("Failed to pop data from stack");
		/* free data */
		free(ptr);
	}
	for (int8_t i=0; i <= 10; ++i) {
		/* create data */
		ptr = (struct data*)malloc(sizeof(struct data));
		memset((void*)ptr, 0, sizeof(struct data));
		ptr->num = i;
		/* push to stack */
		retval = mystack_push(&stack, (void*)ptr);
		if(retval != 0)
			puts("Failed to push data to stack");
	}
	for (int8_t i=0; i <= 30; ++i) {
		/* pop data */
		retval = mystack_pop(&stack, (void**)&ptr);
		if(retval != 0)
			puts("Failed to pop data from stack");
		/* free data */
		free(ptr);
	}
	mystack_destroy(&stack);
	return 0;
}
