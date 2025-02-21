# 373. Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Constraints:

* 1 <= nums1.length, nums2.length <= 105
* -109 <= nums1[i], nums2[i] <= 109
* nums1 and nums2 both are sorted in non-decreasing order.
* 1 <= k <= 104
* k <= nums1.length * nums2.length

## Solution: priority queue
See the following example:

    nums1 = [1,2,4,5,6], nums2 = [3,5,7,9], k = 20

Let i and j be the indexes of nums1 and nums2. Since both nums1 and nums2 are sorted, the first pair is clearly (1, 3), i = 0, j = 0.

For the next pair, there're 2 options: increment i or j.

* option1: (1, 5), i = 0, j = 1
* option2: (2, 3), i = 1, j = 0

After comparing, we found sum of (2, 3) is smaller, so the 2nd pair is (2, 3).

Starting from 2nd pair (2, 3), again we have 2 options: increment i or j.

* option1: (4, 3), i = 2, j = 0
* option2: (2, 5), i = 1, j = 1

However, there's actually an option 3, which is the pair we didn't choose from last step: (1, 5), i = 0, j = 1.

So our target is clear: each time we generate 2 new pairs, one by incrementing i and the other by incrementing j. Then we compare these 2 pairs together with unused pairs from previous steps, and find the one with the smallest sum. This will be the next pair in the result.

So we're actually looking for the smallest item in a dynamic data set. This means we should use heap/priority queue:

* Each time we generate 2 new pairs, we add them into priority queue.
* There might be duplicated pairs. So we use a hash set to ignore duplicated ones.
