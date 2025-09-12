# 2787. Ways to Express an Integer as Sum of Powers
Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:

* n = 41 = 4.
* n = 31 + 11 = 4.

Constraints:

* 1 <= n <= 300
* 1 <= x <= 5

## Solution 1: Dynamic programming(0-1 knapsack problem)
This is a 0-1 knapsack problem in disguise. In a 0-1 knapsack problem, we're given a collection of elements we can use to make up a total sum. In this problem, we're not explicitly given the elements, but we can calculate them: 1^x, 2^x, 3^x, ..., y^x.

First, let's generate the all the elements and save them into list `pows`. We can start from 1^x, 2^x, 3^x, ..., until `y^x > n`.

Second, define dp[i][j] as the number of ways to sum up to `i` using elments `pows[0, j)`. For each dp[i][j], there're 2 possible options:

1. We put pows[j-1] into our knapsack and convert it into a subproblem: `dp[i][j] = dp[i - pows[j-1]][j-1]` (if `i >= pows[j-1]` is true)
2. We don't put pows[j-1] into our knapsack: `dp[i][j] = dp[i][j-1]`.

The result should be the sum of both options: `dp[i][j] = dp[i][j-1] + dp[i - pows[j-1]][j-1]`, if `i >= pows[j-1]` is true.

Base cases: dp[0][j] is always 1. Although all the elements we can use are positive, to get a total sum of 0, we can always choose not to put them into the knapsack. Thus there's always 1 way to get a total sum of 0.

## Solution 2: Space-optimized dynamic programming
In solution 1, there're several places that can be space-optimized.

First, each `dp[i][j]`, we only need the value of `pows[j-1]`. This means we don't have store pow values. We can just dynamically calculate it for each loop.

Second, dp[i][j] automatically inherit the value of dp[i][j-1], which is the value from previous loop. Besides, dp[i][j] may need the value of dp[i - pow][j-1], which is also an value from previous loop. If we iterate j from large to small value, we can safely get values from previous loop without overwriting them.

