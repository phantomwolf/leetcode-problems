package main

import (
	"fmt"
)

func make_counter() func() int {
	count := 0
	return func() int {
		count++
		return count
	}
}

func main() {
	c1 := make_counter()
	c2 := make_counter()
	fmt.Println(c1())
	fmt.Println(c2())
	fmt.Println(c1())
	fmt.Println(c2())
}
