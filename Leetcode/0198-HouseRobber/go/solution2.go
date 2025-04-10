func rob(nums []int) int {
	maxRobPrevPrev := 0
	maxRobPrev := 0
	var maxRob int
	for i := 0; i < len(nums); i++ {
		maxRob = max(maxRobPrevPrev+nums[i], maxRobPrev)
		// Proceed to next
		maxRobPrevPrev = maxRobPrev
		maxRobPrev = maxRob
	}
	return maxRob
}