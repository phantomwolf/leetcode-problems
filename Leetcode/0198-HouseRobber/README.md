# 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

* 1 <= nums.length <= 100
* 0 <= nums[i] <= 400

## Solution 1: DP
Define dp[i] as the max gain of robbing houses [i, n), while n is the length of nums[]. For i-th house, we have two options:

* If we rob house i, we can't robe house i+1. Max gain `dp[i] = nums[i] + dp[i+2]`
* If we don't rob house i, max gain will be the same as robbing houses [i+1, n): `dp[i] = dp[i+1]`

We choose the greater value between those two: `dp[i] = max(nums[i]+dp[i+2], dp[i+1])`.

Time complexity: O(n). Space complexity: O(n).

## Solution 2: Space-optimized DP
In solution 1, dp[i] only relies on dp[i+2] and dp[i+1]. Thus we only need 3 variables instead of a dp[] array.

Time complexity: O(n). Space complexity: O(1).
