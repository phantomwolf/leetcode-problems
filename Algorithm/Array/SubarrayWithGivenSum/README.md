# Find subarray with given sum(Nonnegative Numbers)
Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number. 

## 暴力解法
双层循环，计算每个subarray的sum，看是否与目标相等。时间复杂度O(n^2)。

## O(n)解法
很多数组的问题都能用O(n)的时间来解决。设我们要

Initialize a variable curr_sum as first element. curr_sum indicates the sum of current subarray. Start from the second element and add all elements one by one to the curr_sum. If curr_sum becomes equal to sum, then print the solution. If curr_sum exceeds the sum, then remove trailing elements while curr_sum is greater than sum.

# Find subarray with given sum(Handles Negative Numbers)
Given an unsorted array of integers, find a subarray which adds to a given number. If there are more than one subarrays with the sum as the given number, print any of them.

## O(n)解法
用一个变量curr_sum记录当前扫描过的元素的和，并存入map。之后，若curr_sum - target存在与map中，我们就找到了一个正确的结果。例如：

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33

当扫描到arr[4]时，curr_sum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] = 38，map中有1, 5, 25, 28等元素，其中：

* 1 = arr[0]
* 5 = arr[0] + arr[1]
* 25 = arr[0] + arr[1] + arr[2]
* 28 = arr[0] + arr[1] + arr[2] + arr[3]

curr_sum - sum = 38 - 33 = 5 = arr[0] + arr[1]存在与map中，这说明：

    (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) - (arr[0] + arr[1]) = sum

即：

    arr[2] + arr[3] + arr[4] = sum

我们找到了一个正确答案。
