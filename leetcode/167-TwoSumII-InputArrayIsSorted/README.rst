167. Two Sum II - Input array is sorted 
=======================================================
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input
--------------
numbers={2, 7, 11, 15}, target=9

Output
--------------
[index1, index2]

Solution
--------------
这道题与普通的Two Sum问题的不同之处为，其输入数组是有序的。所以我们可以用双指针的解法。设置两个指针i与j，分别指向开头与结尾。若numbers[i] + numbers[j] < target，说明相加的合还不够大，因此要将i++（由于数组有序，numbers[i+1]必然比numbers[i]大）；若numbers[i] + numbers[j] > target，则j--。当numbers[i] + numbers[j] == target时，我们就找到了想要的结果。
