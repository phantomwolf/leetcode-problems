package main

import (
	"fmt"
)

func main() {
	var i int = 386
	var j int = 486
	var p1 *int = &i
	var p2 *int = &j
	fmt.Println(p2 - p1)
}
