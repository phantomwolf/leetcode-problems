package main

func lengthOfLongestSubstring(s string) int {
	// Corner case
	if len(s) == 0 {
		return 0
	}
	res := 0
	count := make(map[byte]int)
	duplicates := 0
	i, j := 0, 0
	for j < len(s) {
		c := s[j]
		j++
		count[c]++
		if count[c] == 2 {
			// We got a new duplicate
			duplicates++
		}
		// Option 1: update result after expanding window(if there's no duplicates)
		if duplicates == 0 {
			res = max(res, j-i)
		}
		// Shrink window
		for duplicates > 0 {
			d := s[i]
			i++
			count[d]--
			if count[d] == 1 {
				duplicates--
			}
		}
		// Option 2: update result after shrinking window(duplicates already removed)
		//res = max(res, j-i)
	}
	return res
}
