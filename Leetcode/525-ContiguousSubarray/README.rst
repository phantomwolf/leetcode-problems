525 Contiguous Array
====================================
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1::

    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2::

    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.


暴力解法
--------------------------
双层循环，计算每个子数组中的0和1的数量。若相等，则跟当前最长长度相比。


相对值
--------------------------
使用一个count变量，当遇到0是将其减1，遇到1时加1。可知，当count为0时，0和1的数量相等。

我们顺序遍历数组。当任何时候，count为0时，这表示从开头到现在的位置，遇到的0和1的数量相等。不仅如此，若遍历中遇到了2个相同的count值，那么这两个位置之间的元素也拥有相同数量的0和1。

我们用一个哈希表，记录已经出现过的、最靠左的count值，和它们的位置。当我们计算出一个新的count时，找一找map中是否已经出现过同样的count，若存在，则计算一下对应的子数组的长度；若不存在，则把count和目前的位置存入map。
