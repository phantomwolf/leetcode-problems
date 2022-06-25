# 2035. Partition Array Into Two Arrays to Minimize Sum Difference
You are given an integer array nums of N = 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

Example 1:

    Input: nums = [3,9,7,3]
    Output: 2
    Explanation: One optimal partition is: [3,9] and [7,3].
    The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

Example 2:

    Input: nums = [-36,36]
    Output: 72
    Explanation: One optimal partition is: [-36] and [36].
    The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

Example 3:

    Input: nums = [2,-1,0,4,-2,-9]
    Output: 0
    Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
    The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

Constraints:

* 1 <= n <= 15
* nums.length == N == 2 * n
* -107 <= nums[i] <= 107

## Solution
This problem can't be solved using Dynamic Programming. Because in order for dynamic programming to be applicable, the problem must have 2 key attributes:

1. Optimal substructure: the solution to a given optimization problem can be obtained by the combination of optimal solutions to its sub-problems
2. Overlapping sub-problems: the problem can be broken down into subproblems which are reused several times or a recursive algorithm for the problem solves the same subproblem over and over rather than always generating new subproblems

This problem doesn't have optimal substructure.

### Brute force
First calculate the sum of the entire array. Then find all subsets of length n, calculate their sums, and find the minimum diff. The time complexity of finding all subsets is O(2^N).

### Meet in the middle

https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/1513298/C%2B%2B-Meet-In-Middle

Calculating subsets of a large array takes a lot of time. The "Meet in the middle" technique can reduce the time complexity from `O(2^N)` to `O(2^(N/2) * log(2^(N/2)))`.

1. Split the input array into 2 subsets say A and B. A having first n/2 integers and B having rest.
2. Find all possible subset sums of A & B and save them to X & Y. Hence, Size of each of the array X and Y will be at most `O(2^(n/2))`.
3. Find a subset sum P with a size of `sz` in A, and a subset sum Q with a size of `N/2 - sz`. If we merge them together, we'll get the sum of a subset with a size of `N/2`. The sum of the remaining numbers will be `totalSum - P - Q`. The difference mentioned in the problem will be |totalSum - 2P - 2Q|.
4. Repeat step 3 for every subset sum in X. Use a variable to track the minimum difference.

In step 3, given a subset sum P with a size of `sz`, we need to quickly find a subset sum Q with a size of `N/2 - sz`. To achieve this, we can:

- Group subset sums by the size of the subsets
- Sort the subset sums in Y, and use binary search to find the corresponding Q.
