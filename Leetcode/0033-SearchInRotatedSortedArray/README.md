# 33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

Example 3:

    Input: nums = [1], target = 0
    Output: -1

Constraints:

* 1 <= nums.length <= 5000
* -104 <= nums[i] <= 104
* All values of nums are unique.
* nums is an ascending array that is possibly rotated.
* -104 <= target <= 104

## Solution: binary search
Let's draw a graph about example 1. The height of each element represents its value.

```
            7
        6
    5
4
                        2
                    1
                0
```

We can see the array is divided into 2 parts: part 1 `{4,5,6,7}` and part 2 `{0,1,2}`.

Let `lo = 0, hi = nums.length - 1 = 6` and do binary search. During the search `mi = (lo + hi) / 2` might be in part 1 or part 2.

**case 1: nums[mi] is target**

In this case, `mi` is the index of the target.

**case 2: nums[mi] is in part 1**

- If `nums[lo] <= target < nums[mi]`, search left: `hi = mi - 1`
- Otherwise, search right: `lo = mi + 1`

**case 3: nums[mi] is in part 2**

- If `nums[mi] < target <= nums[hi]`, search right: `lo = mi + 1`
- Otherwise, search left: `hi = mi - 1`

The rest is the same as ordinary binary search.
