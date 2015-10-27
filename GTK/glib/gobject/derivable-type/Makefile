main: main.o example-person.o example-boss.o
	gcc -Wall `pkg-config --cflags gobject-2.0` -o main main.o example-person.o example-boss.o `pkg-config --libs gobject-2.0`

main.o: main.c
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o main.o main.c `pkg-config --libs gobject-2.0`

example-boss.o: example-person.o example-boss.c
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o example-boss.o example-person.o example-boss.c `pkg-config --libs gobject-2.0`

example-person.o: example-person.c
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o example-person.o example-person.c `pkg-config --libs gobject-2.0`

.PHONY: clean
clean:
	rm *.o *.so main
