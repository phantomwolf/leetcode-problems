# 1345. Jump Game IV
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

* i + 1 where: i + 1 < arr.length.
* i - 1 where: i - 1 >= 0.
* j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.

Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

Constraints:

* 1 <= arr.length <= 5 * 104
* -108 <= arr[i] <= 108

## Solution 1: BFS
Each index in the array is a node in a graph. We can do BFS from the starting index 0 and see how many steps we need to reach the last index.

Each index i is connected to the following indexes:

1. i-1, if i-1 >= 0
2. i+1, if i+1 < arr.size()
3. j if arr[i] == arr[j]

The tricky part is the 3rd case:

* We can build a `valueToIndex` hash map to find all indexes with the same value quickly.
* The "same value jump" should only be used once per value: suppose arr[i] = arr[j] = arr[k] = val, when we first visit i, next step we should jump to j and k. However, when we visit j or k, is it really necessary to query `valueToIndex` again to find all indexes with the same value? The answer is clearly no, because we already visited all of them when visiting neighbors of i. So after quering `valueToIndex`, we should either remove the key, or clear the corresponding value.

## Solution 2: Bi-directional BFS
To make the algorithm faster, we can do bi-directional BFS.