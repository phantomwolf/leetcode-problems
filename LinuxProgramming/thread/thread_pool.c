#include "thread_pool.h"
#include <signal.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* do nothing here */
void do_nothing(void)
{
}

/* wait for a single signal */
int wait_for_signal(int signum)
{
	int signo = 0;
	sigset_t sigset;
	if (sigemptyset(&sigset) != 0) {
		return -1;
	}
	if (sigaddset(&sigset, signum) != 0) {
		return -1;
	}
	if (sigwait(&sigset, &signo) != 0) {
		return -1;
	}
	return 0;
}

/* start routine of the threads */
int thread_loop(struct thread_pool* pool)
{
	struct thread_pool_task* task_ptr;
	while(true) {
		/* exit thread if pool is destroyed */
		if(pool->enabled == false) {
			pthread_exit((void*)0);
		}

		task_ptr = NULL;
		if(pthread_mutex_trylock(&pool->mutex) == 0) {
			for(int8_t i=0; i < pool->max_task_count; ++i) {
				if(pool->tasks[i] != NULL) {
					task_ptr = pool->tasks[i];
					pool->tasks[i] = NULL;
					break;
				}
			}
			if(pthread_mutex_unlock(&pool->mutex) != 0) {
				puts("Fatal error: failed to "
					"unlock mutex of thread pool");
				exit(1);
			}
		}
		/* run task */
		if(task_ptr != NULL) {
			(*task_ptr->func)(task_ptr->arg);
		}
		/* Wait for SIGALRM signal */
		pause();
	}
}

/* wake up all the threads within the pool
* by sending SIGALRM to them */
int thread_pool_wakeup(struct thread_pool* pool)
{
	for(int8_t i=0; i < pool->pool_size; ++i) {
		pthread_kill(pool->thread_ids[i], SIGALRM);
	}
	return 0;
}

/* create a thread pool */
int thread_pool_init(struct thread_pool* pool, 
			int8_t pool_size, int8_t max_task_count)
{
	/* SIGALRM is used to wakeup threads */
	signal(SIGALRM, (void*)do_nothing);

	pool->enabled = true;
	pool->pool_size = pool_size;
	pool->max_task_count = max_task_count;
	pool->thread_ids = (pthread_t*)calloc(sizeof(pthread_t), pool_size);
	pool->tasks = (struct thread_pool_task**)
		calloc(sizeof(struct thread_pool_task*), max_task_count);
	for(int8_t i=0; i < pool->max_task_count; ++i) {
		pool->tasks[i] = NULL;
	}
	/* init mutex */
	pthread_mutexattr_t mutex_attr;
	pthread_mutexattr_init(&mutex_attr);
	/* enable recursive lock */
	pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&pool->mutex, &mutex_attr);
	pthread_mutexattr_destroy(&mutex_attr);
	/* create threads */
	for(int8_t i=0; i < pool->pool_size; ++i) {
		pthread_create(&pool->thread_ids[i], NULL, 
				(void*)thread_loop, (void*)pool);
	}
	return 0;
}

/* destroy a thread pool */
int thread_pool_destroy(struct thread_pool* pool)
{
	/* stop threads */
	pool->enabled = false;
	thread_pool_wakeup(pool);
	/* release memory */
	free(pool->thread_ids);
	pool->pool_size = 0;
	for(int8_t i=0; i < pool->max_task_count; ++i) {
		free(pool->tasks[i]);
	}
	free(pool->tasks);
	pool->max_task_count = 0;
	return 0;
}

/* add task to thread pool */
int thread_pool_task_add(struct thread_pool* pool,
			void (*func)(void*), void* arg)
{
	for(int8_t i=0; i < pool->max_task_count; ++i) {
		if(pool->tasks[i] == NULL) {
			pool->tasks[i] = (struct thread_pool_task*)
				malloc(sizeof(struct thread_pool_task));
			pool->tasks[i]->func = func;
			pool->tasks[i]->arg = arg;
			/* wake up threads */
			thread_pool_wakeup(pool);
			return 0;
		}
	}
	/* task pool is full */
	return -1;
}
