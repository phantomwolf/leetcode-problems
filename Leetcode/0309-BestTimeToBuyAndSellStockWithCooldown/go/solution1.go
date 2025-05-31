func maxProfit(prices []int) int {
    n := len(prices)
    if n == 1 {
        return 0
    }
    // dp[i][s]: max profit on i-th day. s indicates whether we hold stock or not
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 2)
    }
    // Base cases
    dp[0][1] = -prices[0];                          // Day 0, after buying, we hold stock
    dp[1][0] = max(dp[0][0], dp[0][1]+prices[1])    // Day 1, after resting or selling stock, we don't hold stock
    dp[1][1] = max(dp[0][1], -prices[1])            // Day 1, after resting or buying stock, we hold stock
    for i := 2; i < n; i++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
    }
    return dp[n-1][0]
}
