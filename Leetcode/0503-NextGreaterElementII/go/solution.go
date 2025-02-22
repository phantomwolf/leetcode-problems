func nextGreaterElements(nums []int) []int {
	n := len(nums)
	// Fill in -1 into answer array as default value
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	// monotone stack
	stack := []int{}
	for i := 0; i < 2*n-1; i++ {
		// Keep poping elements if nums[i] > nums[stack[len(stack)-1]]
		for len(stack) > 0 && nums[i%n] > nums[stack[len(stack)-1]] {
			ans[stack[len(stack)-1]] = nums[i%n]
			// Pop element
			stack = stack[0 : len(stack)-1]
		}
		// Push nums[i] to stack
		stack = append(stack, i%n)
	}
	return ans
}