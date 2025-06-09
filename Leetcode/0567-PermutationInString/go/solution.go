func checkInclusion(s1 string, s2 string) bool {
    // Edge case
    if len(s2) < len(s1) {
        return false
    }

    count1 := make(map[byte]int)
    count2 := make(map[byte]int)
    for i := range s1 {
        count1[s1[i]]++
    }

    left, right := 0, 0
    matched := 0
    for right < len(s2) {
        // Expand window
        c := s2[right]
        right++
        if count1[c] > 0 {
            count2[c]++
            if count2[c] == count1[c] {
                matched++
            }
        }
        // Shrink window
        for right-left >= len(s1) {
            // Update result
            if matched == len(count1) {
                return true
            }
            d := s2[left]
            left++
            if count1[d] > 0 {
                if count2[d] == count1[d] {
                    matched--
                }
                count2[d]--
            }
        }
    }
    return false
}