034 Search for a Range
===================================================
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4]. 

Approach #2 Binary Search [Accepted]
---------------------------------------------
由于数组是有序的，所以可以用二分查找。普通的二分查找遇到任意一个target就会立刻退出，这里我们需要做一些修改，使得函数接受一个额外的bool参数left。当left == true时，寻找最左边的target；当left == false时，寻找最右边target的右边的位置(结果需要减去1)。
