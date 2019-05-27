# Problem
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

# 问题
有两个已排序的数组nums1和nums2，它们的长度分别为m和n。找出这两个数组的中位数（即把两个数组合并并排序后，位于正中间的数。如果合并后数组长度为偶数，则求正中间两个数的平均值），要求不能把两个数组合并。
分析
可以转化为一个更宽泛的问题：有两个已排序的数组nums1和nums2，求合并后的第k小的数（如果合并后长度为偶数，则求第k和k+1小的数的平均值）。在本问题中，k值为(m+n)/2。为了简化，以下解法只查找第k小的数。

## 解法1
类似归并排序的合并过程。不断比较nums1和nums2开头的数，并将较小的一个抛弃，直到第k个数。复杂度O(m+n)

## 解法2
假定k为偶数。将nums1中k/2小的数a与nums2中k/2小的数b进行比较。若a < b，nums1中的前k/2个数就可以丢弃。
在例1中，k = (2+1）/2 +１＝2, k/2 = 1. 比较nums1[k/2 – 1]与nums2[k/2 – 1]可知，前者比较小，丢弃nums1[0]到nums1[k/2 – 1]的数，剩下nums1: [3]和nums2: [2]，此时k = 2 – 1 = 1。当k = 1时，选择两个数组开头较小的数字，所以median = 2。

### 为什么可以丢弃nums1[0]到nums1[k/2 – 1]？
Assume that the number of elements in A and B are both larger than k/2, and if we compare the k/2-th smallest element in A(i.e. A[k/2-1]) and the k-th smallest element in B(i.e. B[k/2 - 1]), there are three results:
(Becasue k can be odd or even number, so we assume k is even number here for simplicy. The following is also true when k is an odd number.)

* A[k/2-1] = B[k/2-1]
* A[k/2-1] > B[k/2-1]
* A[k/2-1] < B[k/2-1]

if A[k/2-1] < B[k/2-1], that means all the elements from A[0] to A[k/2-1](i.e. the k/2 smallest elements in A) are in the range of k smallest elements in the union of A and B. Or, in the other word, A[k/2 - 1] can never be larger than the k-th smalleset element in the union of A and B.

## Why?
We can use a proof by contradiction(归谬法). Since A[k/2 - 1] is larger than the k-th smallest element in the union of A and B, then we assume it is the (k+1)-th smallest one. Since it is smaller than B[k/2 - 1], then B[k/2 - 1] should be at least the (k+2)-th smallest one. So there are at most (k/2-1) elements smaller than A[k/2-1] in A, and at most (k/2 - 1) elements smaller than A[k/2-1] in B.So the total number is k/2+k/2-2, which, no matter when k is odd or even, is surly smaller than k(since A[k/2-1] is the (k+1)-th smallest element). So A[k/2-1] can never larger than the k-th smallest element in the union of A and B if A[k/2-1]<B[k/2-1];
Since there is such an important conclusion, we can safely drop the first k/2 element in A, which are definitaly smaller than k-th element in the union of A and B. This is also true for the A[k/2-1] > B[k/2-1] condition, which we should drop the elements in B.
When A[k/2-1] = B[k/2-1], then we have found the k-th smallest element, that is the equal element, we can call it m. There are each (k/2-1) numbers smaller than m in A and B, so m must be the k-th smallest number. So we can call a function recursively, when A[k/2-1] < B[k/2-1], we drop the elements in A, else we drop the elements in B.


We should also consider the edge case, that is, when should we stop?
1. When A or B is empty, we return B[k-1]( or A[k-1]), respectively;
2. When k is 1(when A and B are both not empty), we return the smaller one of A[0] and B[0]
3. When A[k/2-1] = B[k/2-1], we should return one of them

