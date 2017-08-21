package main

import (
	"fmt"
)

func longestValidParentheses(s string) int {
	var longest int = 0
	var stack = []int{-1}
	for i, c := range s {
		fmt.Printf("%d: %c\n", i, c)
		if c == '(' {
			stack = append(stack, i)
			fmt.Printf("pushed %d into stack: %v\n", i, stack)
			continue
		}
		// pop stack if not empty
		if len(stack) != 0 {
			stack = stack[:len(stack)-1]
			fmt.Printf("popped stack: %v\n", stack)
		}
		if len(stack) == 0 {
			stack = append(stack, i)
			fmt.Printf("pushed %d into stack: %v\n", i, stack)
		} else {
			length := i - stack[len(stack)-1]
			fmt.Printf("length: %d\n", length)
			if length > longest {
				longest = length
			}
		}
	}
	return longest
}

func main() {
	var s string = ")()())"
	var ret int = longestValidParentheses(s)
	fmt.Println(ret)
}
