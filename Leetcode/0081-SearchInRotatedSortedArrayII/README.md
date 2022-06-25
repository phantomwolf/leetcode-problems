# 81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed)`. For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index 5 and become `[4,5,6,6,7,0,1,2,4,4]`.

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true

Example 2:

    Input: nums = [2,5,6,0,0,1,2], target = 3
    Output: false

Constraints:

* 1 <= nums.length <= 5000
* -104 <= nums[i] <= 104
* nums is guaranteed to be rotated at some pivot.
* -104 <= target <= 104

## Binary search solution
Time complexity: O(logn). Worst time complexity(when all elements are equal): O(n).

Compared to problem 33, duplicates might exist in the array. So there's an additional special case we need to handle: `nums[lo] = nums[mi] = nums[hi]`.

For example, suppose the input is `[3, ... X, X, X, X, ..., 3]`, X isn't 3. If `nums[mi] = 3`, it's impossible to know if mi comes before or after X.

Suppose `mi = 4`. If input array is `[3, 3, 3, 3, 3, 4, 5, 1, 3]`, mi is on the left side of X; if input array is `[3, 4, 5, 1, 3, 3, 3, 3, 3]`, mi is on the right side of X. Thus we don't know if we should continue searching left or right of mi.

In this special case, we can fallback to linear searching and let both lo and hi move 1 postion: `lo++, hi--`. Once lo or hi reaches an element which is not 3, we can continue binary search. In worst case, when all elements are the same, the entire search will be linear search and the time complexity will fall back to O(n).
