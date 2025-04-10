func canPartition(nums []int) bool {
	totalSum := 0
	for _, val := range nums {
		totalSum += val
	}
	// Edge case
	if totalSum%2 != 0 {
		return false
	}
	target := totalSum / 2
	// Define dp[i][j] as whether it's possible to get a partition of sum j using elements in [0, i)
	dp := make([]bool, target+1)
	// Base case
	dp[0] = true
	for i := 1; i <= len(nums); i++ {
		for j := target; j >= nums[i-1]; j-- {
			dp[j] = dp[j-nums[i-1]] || dp[j]
		}
	}
	return dp[target]
}