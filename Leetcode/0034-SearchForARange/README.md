# 34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109
* nums is a non-decreasing array.
* -109 <= target <= 109

## Solution: binary search
We're searching the left and right boundaries of target(if any). According to labuladong's guides, we usually search in range `[l, r)`, r is exclusive.

### Searching left boundary

1. `l = 0, r = nums.size(), m = l + (r - l)/2`. Explanation: r is exclusive, by setting `r = nums.size()`, index `nums.size()` is already excluded from the range
2. if `nums[m] < target`, continue searching to the right side by `l = m + 1`. Explanation: l is inclusive, in order to exclude m from the range, let `l = m + 1`
3. if `nums[m] > target`, continue searching to the left side by `r = m`. Explanation: r is exclusive, by setting `r = m`, index `m` is already excluded from the range
4. if `nums[m] == target`, continue searching to the left side because we're searching for the left boundary: `r = m`.
5. Since r is exclusive, the loop condition should be `while (l < r)` because when l is equal to r, range `[l, r)` has no element, and the loop must end.

Finally, if target exists in the array, l will stay at their left boundary. If target doesn't exist, l will be either out of index, or at the element which is just greater than target.

### Searching right boundary
When searching for right boundary, we're actually searching for the element which is just greater than target. Most of the logic is the same as left boundary, except:

1. if `nums[m] == target`, continue searching to the right side because we're searching for the right boundary: `l = m + 1`.

Since r is exclusive, the loop condition should be `while (l < r)` because when l is equal to r, range `[l, r)` has no element, and the loop must end.
