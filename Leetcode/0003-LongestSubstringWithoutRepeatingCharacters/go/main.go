/* Use an array to record the last position of a char
*/
package main

import (
    "fmt"
    "math"
)

func lengthOfLongestSubstring(s string) int {
    if len(s) == 0 {
        return 0
    }
    // sliding window
    res := 0
    count := make(map[byte]int)
    repeat := 0
    left, right := 0, 0
    for right < len(s) {
        // Expand window
        c := s[right]
        right++
        count[c]++
        if count[c] == 2 {
            repeat++
        }
        // Update result
        if repeat == 0 {
            res = max(res, right-left)
        }
        // Shrink window
        for repeat > 0 {
            d := s[left]
            left++
            count[d]--
            if count[d] == 1 {
                repeat--
            }
        }
    }
    return res
}