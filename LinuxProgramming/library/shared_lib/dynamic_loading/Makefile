main: main.o
	cd lib/ && make 
	cd ..
	gcc -o main main.o -ldl

main.o:
	gcc -c -o main.o main.c

.PHONY: clean
clean:
	cd lib/; make clean; cd ..
	rm -f *.o main
