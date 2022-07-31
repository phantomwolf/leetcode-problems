# 45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

    Input: nums = [2,3,0,1,4]
    Output: 2

Constraints:

* 1 <= nums.length <= 104
* 0 <= nums[i] <= 1000

## Greedy Solution
Same as Leetcode 55 Jump Game. For each step, we try to jump as far as possible. For input `nums = [3, 1, 3, 1, 0, 1, 1]`

Starting from index 0, we can just 3 positions at most, which means we can reach index range [1, 3] with 1 jump.

Then we try to jump as far as possible from one position within [1, 3]. From index 2, we can jump 3 positions, which is the farthest. So the 2nd jump will be from index 2 to somewhere within [3, 5].

From indexes within [3, 5], the farthest we can jump is from index 5 to the last index. This is the 3rd jump.

Conclusion: 0 -> 2 -> 5 -> 6.
