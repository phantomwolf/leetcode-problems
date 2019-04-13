643. Maximum Average Subarray I
=====================================================
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

Note:

1. 1 <= k <= n <= 30,000.
2. Elements of the given array will be in the range [-10,000, 10,000].


解答
----------------------------------------------
子数组的长度固定，所以我们只需要找到长度为k的子数组中，和最大的一个就行。又要用到累积和数组了。
