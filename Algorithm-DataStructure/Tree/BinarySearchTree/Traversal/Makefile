all: bfs dfs

morris_traversal: bst.o
	gcc -g -o morris_traversal `pkg-config --cflags glib-2.0` morris_traversal.c bst.o `pkg-config --libs glib-2.0`

dfs: bst.o
	gcc -g -o dfs `pkg-config --cflags glib-2.0` dfs.c bst.o `pkg-config --libs glib-2.0`

bfs: bst.o
	gcc -g -o bfs `pkg-config --cflags glib-2.0` bfs.c bst.o `pkg-config --libs glib-2.0`

bst.o:
	gcc -g -c -o bst.o bst.c


.PHONY: clean
clean:
	rm -f *.o bfs dfs morris_traversal
