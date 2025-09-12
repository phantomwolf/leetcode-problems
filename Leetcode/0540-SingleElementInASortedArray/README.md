# 540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:

* 1 <= nums.length <= 10^5
* 0 <= nums[i] <= 10^5

## Solution 1: Counting(naive)
Simply count the number of each element in a hash map or array. Then scan the hash map or array to find the element which only occurs once.

**Space optimization**: if it's allowed to modify the input array, we can directly write the element counts into the input array. Follow these steps:

1. `int val = nums[i]`
2. `nums[i] = 0`
3. `nums[val]++`

Because `0 <= nums[i]`, min value of possible nums[i] is 0 and nums is sorted, so we can safely do `nums[val]++` without out of index or overwriting input values.

## Solution 2: Binary search
Consider input array: `[3,3,7,7,10,11,11]`. If we divide it into 2 halves like this `[3,3,7,7, | 10,11,11]`, the right half's length will be odd because the single element in on the right side. We can use this characteristic to do binary search.

Let `mid = (left + right) / 2`. There're 3 possible cases:

1. nums[mid] is the first one of two duplicated elements: `nums[mid] == nums[mid+1]`
2. nums[mid] is the second one of two duplicated elements: `nums[mid-1] == nums[mid]`
3. nums[mid] is the single element that appears only once.

For case 1, we split the array into 2 groups: `[left, mid-1]` and `[mid+2, right]`. The group with odd length is the one where the single element exists.

For case 2, we split the array into 2 groups: `[left, mid-2]` and `[mid+1, right]`. Again, The group with odd length is the one where the single element exists.

Keep narrowing the range until we found the target.
