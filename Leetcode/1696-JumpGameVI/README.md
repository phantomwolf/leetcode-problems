# 1696. Jump Game VI
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0

Constraints:

* 1 <= nums.length, k <= 105
* -104 <= nums[i] <= 104

## Solution 1: Dynamic Programming(naive)
Define dp[i] as the max score we can get if we jump from 0 to i:

    Base case: dp[0] = nums[0]
    dp[i] = max(dp[j]) + nums[i], j in range [i-k, i-1]

How do we find the max dp[j]? A naive solution is let j loop through [i-k, i-1] and find the max dp[j].

## Solution 2: Dynamic Programming + Priority Queue
We're trying to find the max dp[j], j in range [i-k, i-1]. In other words, we can trying to find the max value in a sliding window of size k. To do this, we use a priority queue.

Tip: how do we make sure that the values inside priority queue are within the k sliding window? Usually we don't remove values from priority queues. Instead, we can check their indexes when they're poped. If they're not in range [i-k, i-1], we simply ignore them and pop another value. To achieve this, we need to push the value's index into the priority queue as well.

