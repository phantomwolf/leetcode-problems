# 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

Constraints:

* 1 <= nums.length <= 2 * 104
* -1000 <= nums[i] <= 1000
* -107 <= k <= 107

## Solution
First, this problem can't be solved by sliding window. Usually with sliding window, expanding the window makes the result greater, while shrinking it makes the result smaller. However, in this problem, elements can be negative, meaning expanding the window might increase or decrease the result.

To get the sum of any subarray, we can use prefix sum technique. Once the prefix sum array is created, the problem is equivalent to: given a `prefixSum[i]`, can we find one or more `prefixSum[j]`, so that `prefixSum[i] - prefixSum[j] = k, j < i`. This is the same as "Two Sum".
