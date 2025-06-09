func minWindow(s string, t string) string {
    countS := make(map[byte]int)
    countT := make(map[byte]int)
    for i := range t {
        countT[t[i]]++
    }
    // Sliding window
    left, right := 0, 0
    matched := 0
    // Record start and end positions of the substring: [start, end)
    start, end := -1, -1
    for right < len(s) {
        // Expand window
        c := s[right]
        right++
        if _, ok := countT[c]; ok {
            countS[c]++
            if countS[c] == countT[c] {
                matched++
            }
        }
        // Shrink window
        for matched == len(countT) {
            // Update result
            if start == -1 || right-left < end-start {
                start = left
                end = right
            }

            d := s[left]
            left++
            if _, ok := countT[d]; ok {
                if countS[d] == countT[d] {
                    matched--
                }
                countS[d]--
            }
        }
    }
    if start == -1 {
        return ""
    }
    return s[start:end]
}