func characterReplacement(s string, k int) int {
    // Edge case
    if len(s) == 1 {
        return 1
    }

    res := 0
    freq := make(map[byte]int)
    maxFreq := 0
    left, right := 0, 0
    for right < len(s) {
        // Expand window
        c := s[right]
        right++
        freq[c]++
        maxFreq = max(maxFreq, freq[c])
        // Can't expand the window. Move window by incrementing left.
        if right-left-maxFreq > k {
            d := s[left]
            left++
            freq[d]--
        }
        res = max(res, right-left)
    }
    return res
}