func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	dp_i2 := 0
	dp_i1 := nums[n-1]
	var dp_i int
	for i := n - 2; i >= 0; i-- {
		dp_i = max(nums[i]+dp_i2, dp_i1)
		dp_i2 = dp_i1
		dp_i1 = dp_i
	}
	return dp_i
}