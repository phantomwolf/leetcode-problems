func maxProfit(prices []int, fee int) int {
	n := len(prices)
	// Base case
	dp_i_0 := 0
	dp_i_1 := -prices[0] - fee
	for i := 1; i < n; i++ {
		old_dp_i_0 := dp_i_0
		old_dp_i_1 := dp_i_1
		dp_i_0 = max(old_dp_i_0, old_dp_i_1+prices[i])
		dp_i_1 = max(old_dp_i_1, old_dp_i_0-prices[i]-fee)
	}
	return dp_i_0
}
