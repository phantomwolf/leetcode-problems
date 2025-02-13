# 1060. Missing Element in Sorted Array
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.

## Example 1:

Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.

## Example 2:

Input: nums = [4,7,9,10], k = 3
Output: 8
Explanation: The missing numbers are [5,6,8,...], hence the third missing number is 8.

## Example 3:

Input: nums = [1,2,4], k = 3
Output: 6
Explanation: The missing numbers are [3,5,6,7,...], hence the third missing number is 6.

## Constraints:

* 1 <= nums.length <= 5 * 104
* 1 <= nums[i] <= 107
* nums is sorted in ascending order, and all the elements are unique.
* 1 <= k <= 108

Follow up: Can you find a logarithmic time complexity (i.e., O(log(n))) solution?

## Solution 1: O(n) solution
通过比较相邻的两个数，我们可以知道两者之间有多少个missing elements：nums[i] - nums[i-1] - 1. 比如，4与7之间的missing elements有5、6，总共是7 - 4 - 1 = 2个。

向右扫描数组nums，并不断把missing elements的数量从k里减去，直到k < nums[i] - nums[i-1] - 1，此时第k个missing element就在nums[i-1]与nums[i]之间，result = nums[i-1] + k。

## Solution 2: O(log(n)) solution
命题：对于nums中任意一个数nums[i]，我们都可以用O(1)时间复杂度计算出[nums[0], nums[i]]之间有多少missing elements。

证明：

    1. 区间[nums[0], nums[i]]中，共有nums[i] - nums[0] + 1个数
    2. 在该范围内，没有missing的数共有i - 0 + 1个。
    3. 两者相减，就是这个范围内missing elements的数量。
