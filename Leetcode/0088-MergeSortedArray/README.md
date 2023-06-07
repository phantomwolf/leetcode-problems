# 88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

 

Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109

 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

## Solution 1
最常见的做法是，创建一个大小为m+n的临时数组tmp，将合并结果写入tmp，最后再写回nums1。时间复杂度O(m + n)，空间复杂度O(m + n)。

## Solution 2
将nums2里的元素写入nums1的后半部分[n, m + n)，再进行插入排序。

## Solution 3
例：nums1 = [1, 3, 5, 0, 0], m = 3, nums2 = [2, 4], n = 2

将nums1里的元素向右移动n个位置，变成nums1 = [1, 3, 1, 3, 5]，这样可以避免nums1中原本的元素被覆盖。设置i、j、k三个下标，n <= i < m + n, 0 <= j < n，0 <= k < m + n。比较nums1[i]和nums2[j]，将较小的元素写入nums1[k]，并更新相应的下标。当i或j越界时，相应元素为INT_MAX.
