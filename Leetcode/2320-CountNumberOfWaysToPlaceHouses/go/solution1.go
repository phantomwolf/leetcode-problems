func countHousePlacements(n int) int {
	// dp[i]: number of ways to place houses with i plots on one side
	dp := make([]int, n+1)
	// Base cases
	dp[0] = 1
	dp[1] = 2
	for i := 2; i <= n; i++ {
		dp[i] = (dp[i-1] + dp[i-2]) % (1e9 + 7)
	}
	return int((dp[n] * dp[n]) % (7 + 1e9))
}