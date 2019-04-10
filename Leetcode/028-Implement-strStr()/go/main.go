package main

import (
	"fmt"
)

func lpsGen(needle string) []int {
	lps := make([]int, len(needle))
	// lps[0] is always 0
	for length, i := 0, 1; i < len(needle); {
		if needle[length] == needle[i] {
			length++
			lps[i] = length
			i++
			continue
		}
		// needle[length] != needle[i]
		if length != 0 {
			// Consider the example AAACAAAA and i = 7
			// 将length回退到已匹配内容的一个适当前缀
			length = lps[length-1]
		} else {
			lps[i] = 0
			i++
		}
	}
	return lps
}

// KMP algorithm
func strStr(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}
	lps := lpsGen(needle)
	for i, j := 0, 0; i < len(haystack); {
		if haystack[i] == needle[j] {
			i++
			j++
			if j == len(needle) {
				return i - j
			}
			continue
		}
		// mismatch
		if i >= len(haystack) {
			return -1
		}
		if j != 0 {
			j = lps[j-1]
		} else {
			i++
		}
	}
	return -1
}

func main() {
	haystack := "ABABDABACDABABCABAB"
	needle := "ABABCABAB"
	index := strStr(haystack, needle)
	fmt.Println(index)
}
