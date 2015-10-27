package main

/*
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

typedef int (*cb)(char *msg);

int callback(char *msg)
{
    printf("callback: %s\n", msg);
    return 233;
}

void caller(char *name, int (*func)(char *msg))
{
    printf("caller: %s\n", name);
    int ret = func("baka");
    printf("ret: %d\n", ret);
}

*/
import "C"

func main() {
    f := C.cb(C.callback)
    C.caller(C.CString("fool"), f)
}
