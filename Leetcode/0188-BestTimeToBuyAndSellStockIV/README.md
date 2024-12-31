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

## Solution 1: DP
Define dp[i][j] as the max profit using prices[0, j) with at most i transactions.

Base cases:

* When no transactions allowed, profit is 0: `dp[0][j] = 0, j ∈ [0, prices.length-1]`
* When no or only 1 price available, we won't be able to sell stock. Profit is 0: `dp[i][0] = 0, dp[i][1] = 0, i ∈ [0, k]`

Suppose i transactions allowed at most, on day j (prices[j-1]), we have 2 choices:

1. Don't sell stock. This way, the profit will be the same as the previous day: `dp[i][j] = dp[i][j-1]`
2. Sell the stock. Suppose the stock was bought with prices[m], m ∈ [0,j-1), the profit will be the profit of this transaction `prices[j-1] - prices[m]`, plus the profit of previous transactions `dp[i-1][m]`:

    dp[i][j] = dp[i-1][m] + prices[j-1] - prices[m]

So the overall expression will be:

    dp[i][j] = max(dp[i][j-1], max(dp[i-1][m] + prices[j-1] - prices[m])), m ∈ [0,j-1)

If the length of prices array is n:

    time complexity: O(k * n^2)
    space complexity: O(kn)

## Solution 2: Optimized DP
By using a variable to track the max value of an expression, we can get rid of the inner most loop and reduce the time complexity to O(nk).

In the previous solution,

    dp[i][j] = max(dp[i][j-1], max(dp[i-1][m] + prices[j-1] - prices[m])), m ∈ [0,j-1)

and we have to use another loop to find the optimal m which makes `dp[i-1][m] + prices[j-1] - prices[m]` as large as possible.

Let's go through the loop:

```java
            for (int j = 2; j <= prices.length; j++) {
                // If we don't sell with prices[j-1]
                dp[i][j] = dp[i][j - 1];
                // If we decide to sell with prices[j-1], we'll have to buy the stock before
                // prices[j-1], which is [0, j-1). Suppose prices[m] is the buying price:
                for (int m = 0; m < j - 1; m++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][m] + prices[j - 1] - prices[m]);
                }
            }
```

First iteration: j = 2, m is in range [0, 0], value of `dp[i - 1][m] - prices[m]` is `dp[i-1][0] - prices[0]`.

Second iteration: j = 3, m is in range [0, 1], value of `dp[i - 1][m] - prices[m]` is `dp[i-1][0] - prices[0]` and `dp[i-1][1] - prices[1]`

Third iteration: j = 4, m is in range [0, 2], value of `dp[i - 1][m] - prices[m]` is `dp[i-1][0] - prices[0]`, `dp[i-1][1] - prices[1]`, and `dp[i-1][2] - prices[2]`.

We can see values of `dp[i - 1][m] - prices[m]` are repreatedly calculated. Instead, we can use a variable `localMax` to track its max value.

Let's look at `dp[i-1][m] + prices[j-1] - prices[m]`. Within this expression, prices[j-1] won't change as m changes, so we just need to find the max value of `dp[i-1][m] - prices[m], m ∈ [0,j-1)`. As we are iterating j, we can use a variable `localMax` to track the value of `dp[i-1][m] - prices[m]`, always prefering larger value. Then any moment, this `localMax` will be the largest `dp[i-1][m] - prices[m]`, which works exactly the same as a loop.
