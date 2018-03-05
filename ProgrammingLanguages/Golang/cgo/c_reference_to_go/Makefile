main: c_reference_to_go.go libtest.so
	go build -o main c_reference_to_go.go

libtest.so: test.o
	gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.1 test.o
	ln -s libtest.so.1.0.1 libtest.so.1
	ln -s libtest.so.1 libtest.so

test.o: test.c
	gcc -o test.o -c -fPIC test.c

.PHONY: clean
clean:
	rm *.o main libtest.so*
