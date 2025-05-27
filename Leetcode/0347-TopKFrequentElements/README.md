# 347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* k is in the range [1, the number of unique elements in the array].
* It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Solution
First, create a map: element as key, and its count as value. Now the problem is the same as finding all K elements whose counts are the largest.

Similar to Kth largest element problem, there're several solutions:

* Sorting: sort by count and find largest K elements
* Max heap: add all counts into the heap, and pop K elements.
* Min heap: add elements into heap, pop elements when its size is larger than K. When the scanning ends, elements inside the heap will be the answers.
* Quick select: in quick select, the array is partitioned into 2 parts. When we find the Kth largest count, on its right will be the answers.
