package main

import (
	"fmt"
)

type V interface {
	sum() int
	show()
}

type Vertex struct {
	X int
	Y int
}

func (v *Vertex) show() {
	fmt.Printf("X: %d, Y: %d\n", v.X, v.Y)
}

func (v *Vertex) sum() int {
	return v.X + v.Y
}

func (v *Vertex) test() {
	fmt.Println("testing")
}

func main() {
	var v V = &Vertex{X: 8, Y: 9}
	//var v Vertex = Vertex{X: 8, Y: 9}
	v.show()
}
