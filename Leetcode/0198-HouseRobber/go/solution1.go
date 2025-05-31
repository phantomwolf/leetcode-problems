func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	// Define dp[i] as max gain of robbing houses [i, n)
	dp := make([]int, n+1) // for convenience, dp[n] = 0
	// Base case
	dp[n-1] = nums[n-1] // Only 1 house available
	for i := n - 2; i >= 0; i-- {
		dp[i] = max(nums[i]+dp[i+2], dp[i+1])
	}
	return dp[0]
}