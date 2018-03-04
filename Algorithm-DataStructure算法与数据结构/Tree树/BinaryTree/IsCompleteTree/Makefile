all: iterative

iterative: bst.o
	gcc -g -o iterative `pkg-config --cflags glib-2.0` iterative.c bst.o `pkg-config --libs glib-2.0`

bst.o:
	gcc -g -c -o bst.o bst.c


.PHONY: clean
clean:
	rm -f *.o iterative
