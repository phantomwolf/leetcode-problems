# 188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Constraints:

* 0 <= k <= 100
* 0 <= prices.length <= 1000
* 0 <= prices[i] <= 1000

## DP solution
Define dp[k][i] as the max profit using prices[0, i] with at most k transactions.

Base cases:

* When no transactions allowed, profit is 0: `dp[0][j] = 0, j ∈ [0, prices.length-1]`
* When only 1 price available, we won't be able to sell stock. Profit is 0: `dp[i][0] = 0, i ∈ [0, k]`

Suppose i transactions allowed in total, on day j (prices[j]), we have 2 choices:

1. Don't sell stock. This way, the profit will be the same as the previous day: `dp[i][j] = dp[i][j-1]`
2. Sell the stock. Suppose the stock was bought with prices[m], m ∈ [0,i), the profit will be the profit of this transaction `prices[i] - prices[m]`, plus the profit of previous transactions: `dp[i][j] = dp[i-1][m] + prices[i] - prices[m]`.

So the overall expression will be:

    dp[i][j] = max(dp[i][j-1], max(dp[i-1][m] + prices[i] - prices[m])), m ∈ [0,j)

**Question: `dp[i-1][m] + prices[i] - prices[m]` indicates we can buy and sell on the same day with prices[m]. Why is this ok?**

Because if we sell and buy on the same day, we'll waste 1 transaction, but it won't affect the profit. Wasting 1 transaction doesn't sound good, but since we're looking for the max profit, this sub-optimal answer will be ignored.

If the length of prices array is n:

    time complexity: O(k * n^2)
    space complexity: O(kn)

## Optimized DP solution
By using a variable to track the max value of an expression, we can get rid of the inner most loop and reduce the time complexity to O(nk).

In the previous solution,

    dp[i][j] = max(dp[i][j-1], max(dp[i-1][m] + prices[i] - prices[m])), m ∈ [0,j)

and we have to use another loop to find the optimal m which makes `dp[i-1][m] + prices[i] - prices[m]` as large as possible.

Let's look at `dp[i-1][m] + prices[i] - prices[m]`. Within this expression, prices[i] won't change as m changes, so we just need to find the max value of `dp[i-1][m] - prices[m]`. As we are iterating j, we can use a variable `localMax` to track the value of `dp[i-1][m] - prices[m]`, always prefering larger value. Then any moment, this `localMax` will be the largest `dp[i-1][m] - prices[m]`, which works exactly the same as a loop.
