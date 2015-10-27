options = -std=c99 -Wall -g
cflags  = `pkg-config --cflags glib-2.0`
libs    = `pkg-config --libs glib-2.0`

main: main.o btree.o
	gcc $(options) $(cflags) -o main main.o btree.o $(libs)

main.o:
	gcc $(options) $(cflags) -c -o main.o main.c $(libs)

btree.o:
	gcc $(options) $(cflags) -c -o btree.o btree.c $(libs)

.PHONY: clean
clean:
	rm *.o main
