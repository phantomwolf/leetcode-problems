package main

import (
	"fmt"
)

// Represent one valid parentheses substring by
// recording its starting index(opening parenthesis) and ending index(closing parenthesis)
type validSubstr struct {
	start int
	end   int
}

// push if opening parenthesis
// pop if closing parenthesis
func longestValidParentheses(s string) int {
	var longest int = 0
	ss := make([]validSubstr) // substr stack. Contains the valid parentheses substrings
	ps := make([]int)         // parentheses stack. Contains the indexes of opening parentheses
	for i, c := range s {
		// If opening parenthesis, push its index to stack
		if c == '(' {
			ps = append(ps, i)
			continue
		}
		// If closing parenthesis and empty ps, clear ss and skip
		if len(ps) == 0 {
			ss = ss[:0]
			continue
		}
		// Pop ps, and add an entry in ss
		vs := validSubstr{ps[len(ps)-1], i}
		ps = ps[:len(ps)-1]
		// Remove smaller substrings which are contained in vs
		for len(ss) != 0 && vs.start <= ss[len(ss)-1].start && vs.end >= ss[len(ss)-1].end {
			ss = ss[:len(ss)-1]
		}
		// Merge adjacent valid substrings
		for len(ss) != 0 && vs.start == ss[len(ss)-1].end+1 {
			vs.start = ss[len(ss)-1].start
			ss = ss[:len(ss)-1]
		}
		// Push vs into ss
		length := vs.end - vs.start + 1
		if length > longest {
			longest = length
		}
		ss = append(ss, vs)
	}
	return longest
}
