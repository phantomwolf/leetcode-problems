# 309. Best Time to Buy and Sell Stock with Cooldown
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

Constraints:

* 1 <= prices.length <= 5000
* 0 <= prices[i] <= 1000

## Solution 1: Generic Dynamic Programming
We can simplify the generic solution from [188. Best Time to Buy and Sell Stock IV](../0188-BestTimeToBuyAndSellStockIV/README.md) by removing the transactions limit.

Define dp[i][s] as the max profit on i-th day, and s indicates whether we hold stock or not.

The max profit on i-th day(no stock in our hand after taking action) `dp[i][0]` has 2 possibilities:

1. `dp[i-1][0]`: we don't hold stock on day i-1 and choose to rest on day i
2. `dp[i-1][1]+prices[i]`: we hold stock on day i-1 and choose to sell on day i

The max profit on i-th day(with stock in our hand after taking action) `dp[i][1]` has 2 possibilities:

1. `dp[i-1][1]`: we hold stock on day i-1 and choose to rest on day i
2. `dp[i-2][0]-prices[i]`: we sold stock on day i-2 and choose to buy on day i

And we choose the max value of them:

    dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])

Note that when `i-2 < 0`, it's not valid. We'll calculate these base cases:

* `dp[0][0] = 0`: on day 0, we choose to rest
* `dp[0][1] = -prices[0]`: on day 0, we choose to buy
* `dp[1][0] = max(dp[0][0], dp[0][1]+prices[1])`: on day 1, we hold no stock after resting, or selling the stock bought on day 0.
* `dp[1][1] = max(dp[0][1], -prices[1])`: on day 1, we hold stock after resting, or buying on day 1. Since we can't sell on day 0, there's no buying limit on day 1.

Time complexity: O(n). Space complexity: O(n).

## Solution 2: Space-optimized Dynamic Programming
In solution 1:

    dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])

We can see `dp[i][0]` only relies on `dp[i-1][0]` and `dp[i-1][1]`, and `dp[i][1]` only relies on `dp[i-1][1]` and `dp[i-2][0]`. We can use several variables to replace the dp[][] array:

* dp[i][0] => dp_i_0
* dp[i][1] => dp_i_1
* dp[i-2][0] => dp_i2_0

