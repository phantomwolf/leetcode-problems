package main

import (
	"fmt"
)

// 枚举类型
type Color int

const (
	RED Color = iota + 8
	GREEN
	BLACK
)

func main() {
	fmt.Printf("%T: %v\n", GREEN, GREEN)
}
