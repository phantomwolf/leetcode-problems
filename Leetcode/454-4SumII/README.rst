454 4Sum II
===========================================
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input::

    A = [ 1, 2]
    B = [-2,-1]
    C = [-1, 2]
    D = [ 0, 2]

Output: 2

Explanation:

The two tuples are:

1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


题目补充
----------------------------
题中说得tuple，指的是A、B、C、D各自的下标组成的元组，而不是元素。这暗示着，重复元素也应该计入结果，因为它们的下标不同。

思路1
----------------------------
采用类似普通4Sum的策略，将数组排序。

首先，固定A和B的下标a和b，令int target = -A[a] - B[b]。那么，问题转换为，求C[c]和D[d]，使得::

    C[c] + D[d] == target

求c与d时，可令c = 0，d = length - 1，分别向另一端前进。若C[c] + D[d] > target，则d--；若C[c] + D[d] < target，则c++；若C[c] + D[d] == target，则找到了一组满足条件的a、b、c、d。

还可以稍微优化一点，可以a、b、c、d略过重复元素，并统计重复元素的数量。由于这些重复元素里，任取4对都能满足条件，所以应当将count_a * count_b * count_c * count_d加入到结果中，并将a、b、c、d前进到下一个不重复的元素。

时间复杂度O(n^3)，但是还是超时了，我们需要更快的算法。

思路2
----------------------------
本类问题有个空间换时间的解法，即将A与B中元素所有可能的sum先计算出来，存入map中，并统计它们的数量。

然后尝试各种可能的C与D的元素之和，看看能令总和为0的A、B元素的sum是否存在于哈希表中，以及它们的数量为多少。

本题非常适合采用此方法，因为元素分属不同的数组，不可能有同一个元素被选用两次，也就不会出现普通4Sum问题中的问题。
