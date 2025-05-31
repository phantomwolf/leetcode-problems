func maxProfit(prices []int) int {
	n := len(prices)
	if n == 1 {
		return 0
	}
	// dp[i][s]: max profit on i-th day. s indicates whether we hold stock or not
	// Base cases
	dp_i_1 := -prices[0]
	dp_i_0 := max(0, dp_i_1+prices[1])
	dp_i_1 = max(dp_i_1, -prices[1])
	dp_i2_0 := 0
	for i := 2; i < n; i++ {
		tmp := dp_i_0
		dp_i_0 = max(dp_i_0, dp_i_1+prices[i])
		dp_i_1 = max(dp_i_1, dp_i2_0-prices[i])
		dp_i2_0 = tmp
	}
	return dp_i_0
}
