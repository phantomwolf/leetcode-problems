package main

import (
	"fmt"
)

func main() {
	array := [3]int{1, 2, 3}
	slice := array[:2]
	slice = append(slice, 8)
	fmt.Println(array)
	fmt.Println(slice)
	slice = append(slice, 9)
	fmt.Println(array)
	fmt.Println(slice)
}
