package main

import (
	"fmt"
	"reflect"
)

type Person interface {
	name() string
}

type Student struct {
	_name string
}

func (s *Student) name() string {
	return s._name
}

func main() {
	var p Person = &Student{_name: "baka"}
	fmt.Println(reflect.TypeOf(p))
}
