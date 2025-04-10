func rob(nums []int) int {
	// Define dp[i] as the max amount of money you can rob using elements in range [0, i)
	dp := make([]int, len(nums)+1)
	// Base case
	dp[0] = 0
	dp[1] = nums[0]
	for i := 2; i <= len(nums); i++ {
		dp[i] = max(dp[i-2]+nums[i-1], dp[i-1])
	}
	return dp[len(nums)]
}