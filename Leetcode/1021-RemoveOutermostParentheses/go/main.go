package main

import (
	"fmt"
)

func removeOuterParentheses(S string) string {
	// left means current amount of left parentheses inside the stack
	left := 0
	res := []byte{}
	for _, c := range S {
		if c == '(' {
			if left != 0 {
				res = append(res, '(')
			}
			left++
			continue
		}
		// c == ')'
		left--
		if left != 0 {
			res = append(res, ')')
		}
	}
	return string(res)
}

func main() {
	input1 := "(()())(())"
	output1 := removeOuterParentheses(input1)
	fmt.Printf("input1: %s\noutput1: %s\n", input1, output1)

	input2 := "(()())(())(()(()))"
	output2 := removeOuterParentheses(input2)
	fmt.Printf("input2: %s\noutput2: %s\n", input2, output2)

	input3 := "()()"
	output3 := removeOuterParentheses(input3)
	fmt.Printf("input3: %s\noutput3: %s\n", input3, output3)

	input4 := "(()())(())(()(()))"
	output4 := removeOuterParentheses(input4)
	fmt.Printf("input4: %s\noutput4: %s\n", input4, output4)
}
