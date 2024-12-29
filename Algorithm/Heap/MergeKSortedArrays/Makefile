cc = gcc
cflags = -g -pipe -Wall

main: heap.o
	$(cc) $(cflags) -o main main.c heap.o

heap.o:
	$(cc) $(cflags) -c -o heap.o heap.c

.PHONY: clean
clean:
	rm -f *.o main
