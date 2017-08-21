compiler = gcc                                                                 
common_opts = -Wall -pipe -std=gnu99                                           
opts = $(if ${DEBUG},-g,-O2)                                                   


program: main.o
	$(compiler) $(common_opts) $(opts) -o program main.o

main.o: main.c
	$(compiler) $(common_opts) $(opts) -c -o main.o main.c

clean:
	rm *.o program
