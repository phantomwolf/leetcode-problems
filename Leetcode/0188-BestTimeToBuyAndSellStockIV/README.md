# 188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

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

* 1 <= k <= 100
* 1 <= prices.length <= 1000
* 0 <= prices[i] <= 1000

## Solution 1: Dynamic programming(generic solution)
Each day, we can perform 3 actions:

1. buy(only if we haven't bought any stock)
2. sell(only if we have bought stock before)
3. rest(do nothing)

In this problem, there're 3 states:

* i: the i-th day
* j: number of transactions
* s: s = 0 means we don't have stock after today's action; s = 1 means we have stock after today's action.

Since buying + selling is one transaction, to make the codes concise, we only decrease j when buying stock.

dp[i][j][0] is the max profit under these conditions:

* on i-th day
* with j transactions
* after resting or selling, we don't have any stock

Since there're 2 possible actions, we choose the greater one between them: `dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i])`

dp[i][j][1] is the max profit under these conditions:

* on i-th day
* with j transactions
* after resting or buying, we have stock

Since there're 2 possible actions, we choose the greater one between them: `dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])`

Base case:

* When j=0, no transactions can be done, so dp[i][0][0] = dp[i][0][1] = 0.
* When i=0, we can only buy stock or rest since it's the first day. If we buy stock, dp[0][j][1] = -prices[0]; if we rest, dp[0][j][0] = 0.

Overall algorithm:

```c++
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][1] = max(
                    dp[i-1][j][1],              // rest
                    dp[i-1][j-1][0]-prices[i]   // buy stock
                );
                dp[i][j][0] = max(
                    dp[i-1][j][0],              // rest
                    dp[i-1][j][1]+prices[i]     // sell stock
                );
            }
        }
```

Time complexity: O(nk). Space complexity: O(nk).
