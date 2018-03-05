package main

import (
	"fmt"
)

type MyFloat float64

func (v *MyFloat) incr(i int) (ret MyFloat) {
	*v += MyFloat(i)
	return *v
}

func main() {
	var f MyFloat = 3.14
	fmt.Println(f.incr(3))
	fmt.Println(f)
}
