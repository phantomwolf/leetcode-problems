package main

import (
	"fmt"
)

/* Dynamic Programming

   dp[i] = n, n is the length of the longest valid
             parentheses substring which ends at s[i]

   case 1: if s[i] == '(', then dp[i] = 0;
   case 2: if s[i] == ')' and s[i-1] == '(', then dp[i] = 2 + dp[i-2]
   case 3: if s[i] == ')' and s[i-1] == ')' and s[i-1-dp[i-1]] == '(', then
       dp[i] = dp[i-1] + 2 + dp[i-2-dp[i-1]]
*/
func longestValidParentheses(s string) int {
	var longest int = 0
	var dp = make([]int, len(s))
	for i := 1; i < len(s); i++ {
		var j int
		// Case 1: s[i] == '('
		if s[i] == '(' {
			continue
		}
		// Case 2: s[i] == ')' and s[i-1] == '('
		if s[i-1] == '(' {
			dp[i] = 2
			if i-2 >= 0 {
				dp[i] += dp[i-2]
			}
			goto track
		}
		// Case 3: s[i] == ')' and s[i-1] == ')' and s[i-1-dp[i-1]] == '('
		j = i - dp[i-1] - 1
		if j >= 0 && s[j] == '(' {
			dp[i] = dp[i-1] + 2
			if j-1 >= 0 {
				dp[i] += dp[j-1]
			}
			goto track
		}
		continue

	track:
		if longest < dp[i] {
			longest = dp[i]
		}
	}
	return longest
}

func main() {
	s := "()(())"
	l := longestValidParentheses(s)
	fmt.Println("result:", l)
}
