main: main.o lib/libmystaticlib.a
	gcc -o main main.o -Llib -lmystaticlib

main.o: main.c
	gcc -c -o main.o main.c

lib/libmystaticlib.a:
	cd lib/
	make clean
	make
	cd ..

.PHONY: clean
clean:
	cd lib/; make clean; cd ..
	rm -f *.o main
