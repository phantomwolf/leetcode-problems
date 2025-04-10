# 213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

Constraints:

* 1 <= nums.length <= 100
* 0 <= nums[i] <= 1000

## Solution: DP
The only difference from [198. House Robber](https://leetcode.com/problems/house-robber-ii/) is houses are placed in a cycle. This means, if house 0 is robbed, we can rob house `len(nums)-1`, and vice versa. The problem is, in 198. House Robber, our dp[] array only calcualtes the max value of moneys we can rob, and we don't know whether house 0 was robbed or not when trying to rob house `len(nums)-1`.

There's a simple way to get rid of this complexity. First, we calculate the max result of robbing houses [0, len(nums)-2]. Second, calculate the max result of robbing houses [1, len(nums)-1]. The final result will be the greater one of these two.
