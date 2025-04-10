func rob(nums []int) int {
	// Edge case
	if len(nums) == 1 {
		return nums[0]
	}
	max1 := simpleRob(nums, 0, len(nums)-2)
	max2 := simpleRob(nums, 1, len(nums)-1)
	return max(max1, max2)
}

// Rob houses in range [left, right]
func simpleRob(nums []int, left int, right int) int {
	maxRobPrevPrev := 0
	maxRobPrev := 0
	var maxRob int
	for i := left; i <= right; i++ {
		maxRob = max(maxRobPrevPrev+nums[i], maxRobPrev)
		// Proceed to next iteration
		maxRobPrevPrev = maxRobPrev
		maxRobPrev = maxRob
	}
	return maxRob
}