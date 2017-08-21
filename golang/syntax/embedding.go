package main

import (
	"fmt"
)

type Reader struct {
	name string
}

func (r *Reader) Read() {
	fmt.Printf("%s: Reading...\n", r.name)
}

type Writer struct {
	name string
}

func (w *Writer) Write() {
	fmt.Printf("%s: Writing...\n", w.name)
}

type ReadWriter struct {
	*Reader
	*Writer
}

func main() {
	// 初始化
	rw := ReadWriter{&Reader{"baka"}, &Writer{"fool"}}
	rw.Read()  // Reader类型的方法Read()
	rw.Write() // Writer类型的方法Write()
	// 访问被隐藏起来的Reader成员
	fmt.Println("reader:", rw.Reader.name)
}
