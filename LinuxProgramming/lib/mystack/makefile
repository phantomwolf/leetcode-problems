compiler = gcc
common_opts = -pthread -Wall -pipe -std=gnu99
opts = $(if ${DEBUG},-g,-O2)

program: mystack.o main.o
	$(compiler) $(common_opts) $(opts) -o program.out main.o mystack.o

main.o: main.c
	$(compiler) $(common_opts) $(opts) -c -o main.o main.c

mystack.o: mystack.c
	$(compiler) $(common_opts) $(opts) -c -o mystack.o mystack.c

clean:
	rm -f *.o *.out

