func mincostTickets(days []int, costs []int) int {
	n := len(days)
	// dp[i]: min cost of traveling days[i, n)
	dp := make([]int, n+1)
	// Base cases
	for i := n - 1; i >= 0; i-- {
		j := i
		// 1-day pass
		for j < n && days[j] < days[i]+1 {
			j++
		}
		dp[i] = costs[0] + dp[j]
		// 7-day pass
		for j < n && days[j] < days[i]+7 {
			j++
		}
		dp[i] = min(dp[i], dp[j]+costs[1])
		// 30-day pass
		for j < n && days[j] < days[i]+30 {
			j++
		}
		dp[i] = min(dp[i], dp[j]+costs[2])
	}
	return dp[0]
}