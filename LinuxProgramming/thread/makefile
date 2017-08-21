compiler = gcc
common_opts = -Wall -pipe -std=gnu99
opts = $(if ${DEBUG},-g,-O2)

program: main.o thread_pool.o
	$(compiler) $(common_opts) $(opts) -o program.out -pthread main.o thread_pool.o
main.o: main.c
	$(compiler) $(common_opts) $(opts) -c -o main.o main.c
thread_pool.o: thread_pool.c
	$(compiler) $(common_opts) $(opts) -c -o thread_pool.o -pthread thread_pool.c



clean:
	rm -f *.o *.out
