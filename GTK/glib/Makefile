glist: glist.c
	gcc -std=c99 -g `pkg-config --cflags glib-2.0` -Wall -o glist glist.c `pkg-config --libs glib-2.0`

.PHONY: clean
clean:
	rm glist
