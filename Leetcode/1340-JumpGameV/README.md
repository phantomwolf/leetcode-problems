# 1340. Jump Game V
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

    i + x where: i + x < arr.length and  0 < x <= d.
    i - x where: i - x >= 0 and  0 < x <= d.

In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

Example 1:

![example1](meta-chart.jpeg)

Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.

Example 2:

Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.

Example 3:

Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies. 

Constraints:

* 1 <= arr.length <= 1000
* 1 <= arr[i] <= 105
* 1 <= d <= arr.length

## Solution 1: Dynamic Programming with Memo
This problem can be solved by Dynamic Programming, because:

* Optimal substructure: we can only jump from a higher position to a lower one. To solve a larger problem(jumping from a higher location), we can first jump to a lower position, then use the subproblem's optimal solution to solve the larger problem.
* Overlapping subproblems: the best result of jumping from each index are repeatedly calculated.

In this problem, smaller problems are indexes with a lower value arr[i], which isn't necessarily on the left side of the array. So it's difficult to determine the order of calculation(unless we compare the values). Thus we're going to use top-down DP with memo solution.

Define a recursive function: `int dp(vector<int>& arr, int index, int d, unordered_map<int, int>& memo)`. The function returns the max number of indices we can visit if we jump from position `index`.

Calculate the result of each index, and the largest one is the solution.