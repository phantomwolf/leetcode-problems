main: main.o
	cd lib/ && make 
	cd ..
	gcc -fPIC -o main main.o -Llib -lmysharedlib

main.o:
	gcc -c -o main.o main.c

.PHONY: clean
clean:
	cd lib/; make clean; cd ..
	rm -f *.o main
