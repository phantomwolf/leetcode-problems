ifeq ($(DEBUG), true)
    options = -std=c99 -Wall -g -pg
else
    options = -std=c99 -Wall -pipe -O2
endif

cflags	= $(shell pkg-config --cflags glib-2.0)
libs	= $(shell pkg-config --libs glib-2.0)

.PHONY: all clean

all: bfs dfs

dfs: dfs.o graph.o
	cc $(options) $(cflags) -o dfs dfs.o graph.o $(libs)

bfs: bfs.o graph.o
	cc $(options) $(cflags) -o bfs bfs.o graph.o $(libs)

dfs.o:
	cc $(options) $(cflags) -c -o dfs.o dfs.c $(libs)

bfs.o:
	cc $(options) $(cflags) -c -o bfs.o bfs.c $(libs)

graph.o:
	cc $(options) $(cflags) -c -o graph.o graph.c $(libs)


clean:
	rm -f *.o bfs dfs
