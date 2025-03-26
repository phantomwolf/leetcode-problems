# 416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:

* 1 <= nums.length <= 200
* 1 <= nums[i] <= 100

## Solution: Dynamic Programming
The problem is equivalent to finding a subset so that the sum of its elements are half of the array's total sum.

Define dp[i][j] as a boolean value to indicate whether it's possible to find a subset using elements in range [0, i) so that the sum of its elements is equal to j. The value of dp[i][j] has two possibilities:

1. If we include element nums[i-1] in the subset, `dp[i][j] = dp[i-1][j-nums[i-1]]`
2. If we don't include element nums[i-1] in the subset, `dp[i][j] = dp[i-1][j]`

If either option is true, dp[i][j] is true: `dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j]`

## Solution: space-optimized DP
In previous solution, we can see the value of dp[i][j] is only related to `dp[i-1][j-nums[i-1]]` and `dp[i-1][j]`, which are the values of the previous row in dp matrix. So the dp array can have only 2 rows, making its space complexity O(sum), sum is the sum of all elements in the array.
