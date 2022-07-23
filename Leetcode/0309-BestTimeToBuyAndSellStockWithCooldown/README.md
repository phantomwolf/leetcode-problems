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

# Solution
The difference between "188. Best Time to Buy and Sell Stock IV" and this problem is, after selling stock, we can't buy stock on the next day. Suppose we sold stock on day i and bought stock on day j, it means we can't sell stock on day j-1. Thus the max profit of previous transactions should be dp[j-2], instead of dp[j-1]:

    dp[i] = dp[j-2] - prices[j] + prices[i], j ∈ [0, i-1]

## Solution 1: inner loop
We can use an inner loop to figure out the max value of `dp[j-2] - prices[j]`.

```java
for (int j = 0; j < i; j++) {
    // Suppose stock was bought on day j,
    // which also means we can't sell stock on day j - 1
    int prevProfit = (j - 2 >= 0) ? dp[j - 2] : 0;
    dp[i] = Math.max(dp[i], prevProfit + prices[i] - prices[j]);
}
```

Time complexity: O(n^2), space complexity: O(n)

## Solution 2: use a variable to track
We can use a variable to track the max value of `dp[j-2] - prices[j]`.

The allowed range of j is [0, i-1], so we use a variable to track the max value of `dp[i-3] - prices[i-1], dp[i] = 0 if i < 0`
