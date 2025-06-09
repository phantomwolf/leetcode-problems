# 977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:

* 1 <= nums.length <= 104
* -104 <= nums[i] <= 104
* nums is sorted in non-decreasing order.
 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

## Solution
This problem is similar to merging two sorted arrays.

In example 2, the input array can be divided into two parts: `[-7,-3 | 2,3,11]`. Both parts are sorted, but in different order. We can introduce 3 indexes:

* `i = 0` and moves to the right.
* `j = n-1` and moves to the left.
* `k = n-1` and moves to the left. Used for writing index of the result.

Each time, we compare `abs(nums[i])` and `abs(nums[j])`, choose the greater one to calculate the square and write to result.

Algorithm:

    i = 0, j = n-1, k = n-1
    if (abs(nums[i]) < abs(nums[j])) {
        result[k] = nums[j] * nums[j]
        j--
        k--
    } else {
        result[k] = nums[i] * nums[i]
        i++
        k--
    }

**What if `i` or `j` cross the boundary of negative and positive numbers?**

This won't be a problem. In example 2, if at some point, `i` points to 2 and `j` points to 3:

    [-7, -3|2, 3, 11]
            i  j

Even `i` crossed the boundary, `abs(nums[i])` won't be greater than `abs(nums[j])`, as the latter part of `nums[]` is sorted as well. So it won't affect our algorithm.
