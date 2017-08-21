package main

import (
	"fmt"
	"unsafe"
)

type SliceHeader struct {
	Data uintptr
	Len  int
	Cap  int
}

func main() {
	a := []byte{3}
	fmt.Println((*SliceHeader)(unsafe.Pointer(&a)))
}
