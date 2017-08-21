program: main.o printf_test.o
	gcc main.o printf_test.o -o program

printf_test.o: printf_test.c
	gcc printf_test.c -c -o printf_test.o


clean:
	rm *.o program
