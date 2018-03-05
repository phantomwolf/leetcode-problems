all: main

main: rbtree.h rbtree.cpp main.cpp
	g++ -o main -g -std=c++11 rbtree.cpp main.cpp

.PHONY: clean

clean:
	rm -f main
