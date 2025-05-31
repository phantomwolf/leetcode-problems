func mostPoints(questions [][]int) int64 {
	n := len(questions)
	if n == 1 {
		return int64(questions[0][0])
	}
	// dp[i]: max points we can get by answering questions  [i, n)
	dp := make([]int64, n)
	// Base case
	dp[n-1] = int64(questions[n-1][0])
	for i := n - 2; i >= 0; i-- {
		solve := int64(questions[i][0])
		if i+questions[i][1]+1 < n {
			solve += dp[i+questions[i][1]+1]
		}
		skip := dp[i+1]
		dp[i] = max(solve, skip)
	}
	return dp[0]
}