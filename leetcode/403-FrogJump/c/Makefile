cc = gcc -g -pipe -Wall
glib_cflags = `pkg-config --cflags glib-2.0`
glib_libs = `pkg-config --libs glib-2.0`


bfs: bfs.c
	$(cc) $(glib_cflags) -o bfs bfs.c $(glib_libs)


.PHONY: clean

clean:
	rm -f *.o main
