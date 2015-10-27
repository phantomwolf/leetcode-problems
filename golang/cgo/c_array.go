package main

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[20];
};

void show_person(struct Person *p)
{
    printf("name: %s\n", p->name);
}

*/
import "C"
//import "unsafe"

func main() {
    person := C.struct_Person{}
    name := "baka"
    var i int
    for i = 0; i < len(name) && i < 19; i++ {
        person.name[i] = C.char(name[i])
    }
    person.name[i] = 0
    C.show_person(&person)
}
