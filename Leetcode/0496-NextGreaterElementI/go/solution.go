func nextGreaterElement(nums1 []int, nums2 []int) []int {
	nextGreaterElement := map[int]int{}
	// Use monotone stack to calculate next greater elements in nums2 and store results hash map
	stack := []int{}
	for i := 0; i < len(nums2); i++ {
		// If new element is larger than stack top, keep poping until new element is smaller or equal to it
		for len(stack) > 0 && nums2[i] > stack[len(stack)-1] {
			nextGreaterElement[stack[len(stack)-1]] = nums2[i]
			stack = stack[0 : len(stack)-1]
		}
		stack = append(stack, nums2[i])
	}
	// Process those without next greater elements
	for i := 0; i < len(stack); i++ {
		nextGreaterElement[stack[i]] = -1
	}
	// Generate answer
	ans := []int{}
	for i := 0; i < len(nums1); i++ {
		ans = append(ans, nextGreaterElement[nums1[i]])
	}
	return ans
}