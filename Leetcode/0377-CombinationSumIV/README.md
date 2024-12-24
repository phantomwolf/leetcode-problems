# 377. Combination Sum IV
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

## Example 1:

Input: nums = [1,2,3], target = 4

Output: 7

Explanation:

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

## Example 2:

Input: nums = [9], target = 3
Output: 0

## Constraints:

* 1 <= nums.length <= 200
* 1 <= nums[i] <= 1000
* All the elements of nums are unique.
* 1 <= target <= 1000

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Solution 1: top-down dynamic programming with memo
Define the result of dp(target) as the number of possible combinations that sum up to target.

Why can this problem be solved using dynamic programming? Define dp(target) as the number of combinations that sum up to target.

* Optimal substructure: to get a combination that sums up to target, first we choose an element from nums[] and place it in the end, then we recursively calculate the number of possible combinations of the remaining part of the combination. In other words, dp(target) = dp(target - nums[0]) + dp(target - nums[1]) + ... + dp(target - nums[nums.length-1]).
* Overlapping sub-problems: the results of sub-problems will be reused more than once. Suppose target = 3 and nums = [1,2], then dp(2) = dp(1) + dp(0), dp(3) = dp(2) + dp(1). We can see the result of dp(1) is reused.

## Solution 2: bottom-up dynamic programming
Define dp[i] as the number of possible combinations that sum up to target:

    dp[i] = dp[i-nums[0]] + dp[i-nums[1]] + ... + dp[i-nums[nums.length-1]]

