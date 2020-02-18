all: id oop

id: id.m
	clang -x objective-c -framework Foundation -o id id.m

oop: oop.h oop.m
	clang -x objective-c -framework Foundation -o oop oop.m


.PHONY: clean

clean:
	rm -f id oop

