libmysharedlib.so: first.o second.o
	gcc -shared -Wl,-soname,libmysharedlib.so.1 -o libmysharedlib.so.1.0.1 first.o second.o
	ln -s libmysharedlib.so.1.0.1 libmysharedlib.so.1
	ln -s libmysharedlib.so.1 libmysharedlib.so

first.o:
	gcc -fPIC -c first.c -o first.o

second.o:
	gcc -fPIC -c second.c -o second.o

.PHONY: clean
clean:
	rm -f *.o *.so *.so.*
