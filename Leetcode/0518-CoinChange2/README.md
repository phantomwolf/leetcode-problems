# 518. Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

## Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4

Explanation: there are four ways to make up the amount:

    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1

## Example 2:

Input: amount = 3, coins = [2]
Output: 0

Explanation: the amount of 3 cannot be made up just with coins of 2.

## Example 3:

Input: amount = 10, coins = [10]
Output: 1

## Constraints:

* 1 <= coins.length <= 300
* 1 <= coins[i] <= 5000
* All the values of coins are unique.
* 0 <= amount <= 5000

## Solution: dynamic programming
Note that the problem asks for combinations, instead of permutations. This means the order of the coins doesn't matter, and we don't want duplicated ones.

Define dp[i][j] as the number of possible combinations which sum up to i, given only coins in [0, j) can be used. Then dp[amount][coins.length] is the answer we want to calculate.

The combinations related to dp[i][j] can be categorized into 2 types:

1. Combinations without coins[j-1]: without using coins[j-1], the number of combinations is the same as dp[i][j-1]
2. Combinations with one or more coins[j-1]: with coins[j-1], first we subtract coins[j-1] from i, then we use coins from [0, j) to sum up to i-coins[j-1]. The range [0, j) doesn't change, because a coin can be used unlimited times. This category has dp[i-coins[j-1]][j] combinations if i-coins[j-1] >= 0.

    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j]


