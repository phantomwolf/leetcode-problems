main: main.o bst.o
	gcc -g -o main main.o bst.o

main.o:
	gcc -g -c -o main.o main.c

bst.o:
	gcc -g -c -o bst.o bst.c


.PHONY: clean
clean:
	rm *.o main
