func minCost(costs [][]int) int {
	n := len(costs)
	// Define dp[i][j] as the min cost of painting houses of range [0, i], and house i is painted as color j
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 3)
	}
	// Base case: painting first house
	dp[0][0] = costs[0][0]
	dp[0][1] = costs[0][1]
	dp[0][2] = costs[0][2]
	for i := 1; i < n; i++ {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0]
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1]
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2]
	}
	return min(dp[n-1][0], dp[n-1][1], dp[n-1][2])
}