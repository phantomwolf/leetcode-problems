package main

/*
#include "test.h"
#include "wrapper.h"


*/
import "C"
import "fmt"

//export go_callback
func go_callback(id C.int) {
    fmt.Println("id: ", id)
}

func main() {
    cb := C.callback(C.go_callback)
    C.caller(cb)

    C.some_c_callback();
}
