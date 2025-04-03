# 2874. Maximum Value of an Ordered Triplet II
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 

Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.

Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.

Constraints:

* 3 <= nums.length <= 105
* 1 <= nums[i] <= 106

## Solution 1: Greedy + rightMax[] array
All elements are positive, so nums[k] is positive. To get `(nums[i] - nums[j]) * nums[k] > 0`, given a fixed j, we must find the max nums[i] on j's left side and max nums[k] on j's right side.

Finding the max nums[i] on the left is easy. Simply use a variable maxI to track the elements scanned. But finding max nums[k] on the right side is tricky, as we haven't scanned the right side yet. Here we have to use a precomuted rightMax[] array: rightMax[j] is the max value in range [j+1, nums.length).

So for each given j, we have a possible result `(nums[i] - nums[j]) * nums[k] = (maxI - nums[j]) * rightMax[j]`. Use a variable maxRes to track the greatest result.

## Solution 2: Greedy
Let's think about this problem in a different perspective: this time we fix k, and try to find the max value of `(nums[i] - nums[j])`.

We use several variables to track our scanning:

* `maxI` is the maximum value we've scanned
* `maxDiff` is the max value of (nums[i] - nums[j])
* `maxRes` is the max value of `(nums[i] - nums[j]) * nums[k]`

Initially:

    maxRes = 0
    maxDiff = nums[0] - nums[1]
    maxI = Math.max(nums[0], nums[1])

Start loop from k = 2. When each iteration begins:

    maxRes is the previous best result before nums[k]
    maxDiff is the max value of (nums[i] - nums[j]) before nums[k]
    maxI is the max element before nums[k]

In the iteration, we do the following in order:

1. maxRes: calculate a new possible value using nums[k] and maxDiff(here maxDiff isn't updated yet)
2. maxDiff: calculate a new possible value using nums[k] and maxI(here maxI isn't updated yet)
3. maxI: calculate a new possible value using nums[k]
