package main

import (
	"fmt"
)

func init() {
	fmt.Println("Init...")
	fmt.Println(glob)
}

var glob string = "baka"

func init() {
	fmt.Println(glob)
}

func main() {
}
