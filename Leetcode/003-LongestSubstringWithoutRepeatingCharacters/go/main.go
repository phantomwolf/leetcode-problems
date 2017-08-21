/* Use an array to record the last position of a char
*/
package main

import (
    "fmt"
    "math"
)

func lengthOfLongestSubstring(s string) int {
    var m = make(map[uint8]int)
    var longest int = -1
    var left int = 0        // left bound of current window
    for i, c := range s {
        pos, ok := m[uint8(c)]
        if !ok || pos < left {
            m[uint8(c)] = i
            continue
        }
        // We got a possible answer
        if i - left > longest {
            longest = i - left
        }
        // Proceed to next
        left = pos + 1
        m[uint8(c)] = i
    }
    // Last possible answer
    if len(s) - left > longest {
        longest = len(s) - left
    }
    return longest
}

func main() {
}
