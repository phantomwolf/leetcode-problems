main: main.o example-chinese.o example-editable.o
	gcc -Wall `pkg-config --cflags gobject-2.0` -o main main.o example-chinese.o example-editable.o `pkg-config --libs gobject-2.0`

main.o:
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o main.o main.c `pkg-config --libs gobject-2.0`

example-chinese.o:
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o example-chinese.o example-chinese.c `pkg-config --libs gobject-2.0`

example-editable.o:
	gcc -Wall `pkg-config --cflags gobject-2.0` -c -o example-editable.o example-editable.c `pkg-config --libs gobject-2.0`

.PHONY: clean
clean:
	rm -f *.o main
