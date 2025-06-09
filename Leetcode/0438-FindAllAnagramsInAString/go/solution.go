func findAnagrams(s string, p string) []int {
    // Edge case
    if len(s) < len(p) {
        return []int{}
    }

    need := make(map[byte]int)
    window := make(map[byte]int)
    for i := range p {
        need[p[i]]++
    }

    res := []int{}
    // Sliding window
    left, right := 0, 0
    matched := 0
    for right < len(s) {
        // Expand window
        c := s[right]
        right++
        if need[c] > 0 {
            window[c]++
            if window[c] == need[c] {
                matched++
            }
        }
        // Shrink window
        for right-left >= len(p) {
            // Update result
            if matched == len(need) {
                res = append(res, left)
            }
            
            d := s[left]
            left++
            if need[d] > 0 {
                if window[d] == need[d] {
                    matched--
                }
                window[d]--
            }
        }
    }
    return res
}