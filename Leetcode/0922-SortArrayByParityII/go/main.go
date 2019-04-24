package main

import (
	"fmt"
)

// sortArrayByParityII implements an inline algorithm
func sortArrayByParityII(A []int) []int {
	odd, even := 1, 0
	for odd < len(A) && even < len(A) {
		if A[odd] & 1 == 1 {
			odd += 2
		} else if A[even] & 1 == 0 {
			even += 2
		} else {
			// swap
			tmp := A[odd]
			A[odd] = A[even]
			A[even] = tmp
		}
	}
	return A
}


func main() {
}