package main

import (
	"fmt"
)

func foo() (res1, res2 int) {
	res1 = 888
	defer func() { res1++; res2 += 2 }()
	return 1, 3 // res1和res2先被赋值为1和3，然后是defer的函数，最后return。
}

func main() {
	res1, res2 := foo()
	fmt.Println(res1, res2)
}
