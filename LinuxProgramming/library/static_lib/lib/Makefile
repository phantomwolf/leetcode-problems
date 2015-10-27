libmystaticlib.a: first.o second.o
	ar rcs libmystaticlib.a first.o second.o

first.o:
	gcc -c first.c -o first.o

second.o:
	gcc -c second.c -o second.o

.PHONY: clean
clean:
	rm -f *.o *.a
