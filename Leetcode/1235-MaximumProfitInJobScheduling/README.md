# 1235. Maximum Profit in Job Scheduling
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:

![Example1](./sample1_1584.png)

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:

![example2](./sample22_1584.png)

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:

![example3](./sample3_1584.png)

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:

* 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
* 1 <= startTime[i] < endTime[i] <= 109
* 1 <= profit[i] <= 104

## Solution 1: sort + dynamic programming
Problems with ranges usually need sorting. Let's create an array `int[][] jobs` to store tuples like `(startTime, endTime, profit)`, then sort it by `endTime`.

**Why sort by `endTime`?** Because if sort by endTime, for any `jobs[i]`, `jobs[0, i-1]` will be divided into 2 parts: `jobs[0, j]` doesn't overlap with `jobs[i]`, and `jobs[j+1, i-1]` overlaps with `jobs[i]`. Why is this true? Because if `jobs[j]` doesn't overlap with `jobs[i]`, it means `jobs[j].endTime <= jobs[i].startTime`, and `jobs[j-1].endTime <= jobs[j].endTime`.

In conclusion, if we sort jobs by endTime, jobs will be divided into 2 continous parts: the left part doesn't overlap with `jobs[i]`, and the right part overlaps with it.

Define dp array as `dp[i]` is the max profit we can get using `jobs[0, i-1]`.

Base case: `dp[0] = 0`, because no job is allowed, thus no profit.

For each `dp[i]`, we have 2 choices:

1. Add `jobs[i-1]` to our selection, and linearly find the largest `j` so that `jobs[j-1]` doesn't overlap with `jobs[i-1]`: `dp[i] = dp[j] + jobs[j-1].profit`.
2. Don't add `jobs[i-1]` to our selection, and value of `dp[i]` is the same as its previous value: `dp[i] = dp[i-1]`.

Always choose the larger value: `dp[i] = max(dp[j] + jobs[i-1].profit, dp[i-1])`.

## Solution 2: sort + dynamic programming + binary search
In solution 1, we linearly search for the `j` value. Since jobs are sorted by endTime, we can use binary search to find it.

For any `jobs[i]`, `jobs[0, i-1]` is divided into 2 continous parts: the left part doesn't overlap with `jobs[i]`, and the right part overlaps with it. We're searching for the right boundary of the left part.
