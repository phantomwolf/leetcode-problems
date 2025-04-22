func summaryRanges(nums []int) []string {
	res := []string{}
	// Edge case
	if len(nums) == 0 {
		return res
	}

	i, j := 0, 1
	for j <= len(nums) {
		if j == len(nums) || nums[j] != nums[j-1]+1 {
			// Generate a range
			if j-1 == i {
				// Single element
				res = append(res, fmt.Sprintf("%d", nums[i]))
			} else {
				// Multiple elements
				res = append(res, fmt.Sprintf("%d->%d", nums[i], nums[j-1]))
			}
			i = j
		}
		j++
	}
	return res
}

/* Verification:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]


len(nums) = 6
i = 0, j = 1, nums[j] = 1 = nums[j-1]+1 = 0 + 1
i = 0, j = 2, nums[j] = 2 = nums[j-1]+1 = 1 + 1
i = 0, j = 3, nums[j] = 4 != nums[j-1]+1 = 2 + 1 = 3, res = ["0->2"]
i = 3, j = 4, nums[j] = 5 = nums[j-1]+1 = 4+1 = 5
i = 3, j = 5, nums[j] = 7 != nums[j-1]+1 = 5+1 = 6, res = ["0->2", "4->5"]
i = 5, j = 6, nums[j] = len(nums), res = ["0->2", "4->5", "7"]

return res
*/