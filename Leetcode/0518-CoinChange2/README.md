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
Note that the problem asks for combinations, instead of permutations.

Define dp[i][j] as the number of possible combinations which sum up to amount `j`, given only coins in [0, i) can be used. Then dp[coins.length][amount] is the answer we want to calculate.

The combinations related to dp[i][j] can be categorized into 2 types:

1. Combinations without `coins[i-1]`: without using `coins[i-1]`, the number of combinations is the same as `dp[i-1][j]`
2. Combinations with one or more `coins[i-1]`: with `coins[i-1]`, first we subtract `coins[i-1]` from amount `j`, then we use coins from `[0, i)` to sum up to `i-coins[j-1]`. The range [0, j) doesn't change, because a coin can be used unlimited times. This category has `dp[i][j-coins[i-1]]` combinations if `i-coins[j-1] >= 0`:

```go
for i := 1; i <= len(coins); i++ {
	for j := 1; j <= amount; j++ {
        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]     // Remember to handle out of index issue
    }
}
```

### Space optimization
dp[i][j] only relies on 2 values:

* `dp[i-1][j]`: in the 2D dp[][] matrix, it's from the row above. If we use 1D array, it will be dp[j] from the previous iteration.
* `dp[i][j-coins[i-1]]`: in the 2D dp[][] matrix, it's from the same row. If we use 1D array, it will be dp[j-coins[i-1]]. Here we still need the `i` index to find the right coin. To make it more readable, we use variable `currCoin` to replace i.

```go
for currCoin := 0; currCoin < len(coins); currCoin++ {
    for i := 1; i <= amount; i++ {
        if i >= coins[currCoin] {
            dp[i] += dp[i-coins[currCoin]]
        }
    }
}
```

Note that space optimization doesn't change the time complexity: still 2 layers of loops.
