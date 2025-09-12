# 162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Constraints:

* 1 <= nums.length <= 1000
* -231 <= nums[i] <= 231 - 1
* nums[i] != nums[i + 1] for all valid i.

## Solution: binary search
First of all, the peak definitely exist, because `nums[-1] = nums[n] = -∞`. This means any `nums[i], 0 <= i < n` will be greater than nums[-1] and nums[n].

In binary search, let `mid = left + (right - left) / 2`. Calculate the previous and next elements of `nums[mid]`:

* `prev = nums[mid-1]` if `i >= 0`; otherwise, `prev = INT_MIN`.
* `next = nums[mid+1]` if `i+1 < nums.length`; otherwise, `next = INT_MIN`.

For every `mid`, first check if we've find the peak element: if `nums[mid]` is greater than both `prev` and `next`, `nums[mid]` is a peak.

Now, how do we determine whether to continue searching to the left or right?

* If `prev > nums[mid]`, there must be at least one peak element on the left. Let `right = mid-1` and continue searching.
* If `next > nums[mid]`, there must be at least one peak element on the right. Let `left = mid+1` and continue searching.

The image below depicts the case that `prev > nums[mid]`. Since `nums[-1] = -∞`, there must be at least one peak value between nums[-1] and nums[mid].

![mid](162-FindPeakElement.png)

