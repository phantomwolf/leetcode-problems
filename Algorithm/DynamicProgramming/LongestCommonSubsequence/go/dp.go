package main

import (
	"fmt"
)

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func lcs(s1 string, s2 string) int {
	if len(s1) == 0 || len(s2) == 0 {
		return 0
	}

	// dp[i][j] is the longest common subsequence length of s1[0:i] and s2[0:j]
	var dp = make([][]int, len(s1)+1)
	for i := 0; i <= len(s1); i++ {
		dp[i] = make([]int, len(s2)+1)
	}

	for i := 0; i < len(s1); i++ {
		for j := 0; j < len(s2); j++ {
			if s1[i] == s2[j] {
				dp[i+1][j+1] = dp[i][j] + 1
				continue
			}
			dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
		}
	}
	return dp[len(s1)][len(s2)]
}

func main() {
	var s1 string = "AGGTAB"
	var s2 string = "GXTXAYB"

	ret := lcs(s1, s2)
	fmt.Println(ret)
}
