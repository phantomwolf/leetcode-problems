libmysharedlib.so: first.o second.o
	gcc -shared -o libmysharedlib.so first.o second.o

first.o:
	gcc -fPIC -c first.c -o first.o

second.o:
	gcc -fPIC -c second.c -o second.o

.PHONY: clean
clean:
	rm -f *.o *.so
