18.4Sum 
====================================
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets. 

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is::

    [ [-1,  0, 0, 1], [-2, -1, 1, 2], [-2,  0, 0, 2] ]


分析
------------------------
经典的NP完全问题，没有特别高效的方法。3Sum可以视为N个2Sum问题，4Sum则可以视为N个3Sum问题。2Sum问题可以借助一个set或者排序，来达到O(n)的级别，那么3Sum就是O(n^2)，4Sum是O(n^3)。

既然总的时间复杂度大于O(nlogn)，我们不妨排序。

空间换时间
------------------------
计算任意2个数的和，放入辅助数组中，就能将问题变为2Sum。记得同一个元素不能重复使用。
