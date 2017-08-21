/* Expand from center */
package main

import (
	"fmt"
)

// Return: length, left, right
func expandFromCenter(
	p *string,
	left int,
	right int) (int, int, int) {
	left, right = left-1, right+1
	for left >= 0 && right < len(*p) && (*p)[left] == (*p)[right] {
		left, right = left-1, right+1
	}
	return right - left - 1, left + 1, right - 1
}

func longestPalindrome(s string) string {
	var longest int = 1
	var left, right int
	// expand from 1 char
	for i := 1; i < len(s)-1; i++ {
		length, l, r := expandFromCenter(&s, i, i)
		if length > longest {
			longest = length
			left, right = l, r
		}
	}
	// expand from 2 char
	for i := 1; i < len(s); i++ {
		if s[i-1] != s[i] {
			continue
		}
		length, l, r := expandFromCenter(&s, i-1, i)
		if length > longest {
			longest = length
			left, right = l, r
		}
	}
	return s[left : right+1]
}

func main() {
	s := "ccc"
	ret := longestPalindrome(s)
	fmt.Println(ret)
}
