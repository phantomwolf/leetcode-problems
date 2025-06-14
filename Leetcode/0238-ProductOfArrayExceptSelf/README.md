# 238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

* 2 <= nums.length <= 105
* -30 <= nums[i] <= 30
* The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## Solution 1: prefix and suffix
In other words, `answer[i] = nums[0] * nums[1] * ... * nums[i-1] * nums[i+1] * ... * nums[n-1]`. We can introduce 2 auxiliary arrays:

* `prefix[i] = nums[0] * nums[1] * ... * nums[i]`
* `suffix[i] = nums[i] * nums[i+1] * ... * nums[n-1]`

With these 2 auxiliary arrays, `answer[i] = prefix[i-1] * suffix[i+1]`. Both prefix[] and suffix[] can be calculated using 1 iteration.

Time complexity: O(n)
Space complexity: O(n)

## Solution 2: space optimization
If you're familair with accumulative sum, you'll know the value of prefix[] can be calculated on the fly. However, suffix[] can't. Luckily, the problem description explicitly says "The output array does not count as extra space for space complexity analysis". This means we can temporarily use answer[] as suffix[].

In the beginning, use answer[] as suffix[] and calculate its values. Then, calculate `prefix` and `answer[i]` at the same time.
