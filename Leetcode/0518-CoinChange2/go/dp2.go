func change(amount int, coins []int) int {
	// dp[i]: number of combinations to make up amount i
	dp := make([]int, amount+1)
	// Base case
	dp[0] = 1

	for currCoin := range coins {
		for i := 1; i <= amount; i++ {
			if i >= coins[currCoin] {
				dp[i] += dp[i-coins[currCoin]]
			}
		}
	}
	return dp[amount]
}