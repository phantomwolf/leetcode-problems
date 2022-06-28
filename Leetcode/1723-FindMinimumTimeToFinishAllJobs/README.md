# 1723. Find Minimum Time to Finish All Jobs
You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

Example 1:

    Input: jobs = [3,2,3], k = 3
    Output: 3
    Explanation: By assigning each person one job, the maximum time is 3.

Example 2:

    Input: jobs = [1,2,4,7,8], k = 2
    Output: 11
    Explanation: Assign the jobs the following way:
    Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
    Worker 2: 4, 7 (working time = 4 + 7 = 11)
    The maximum working time is 11.

Constraints:

* 1 <= k <= jobs.length <= 12
* 1 <= jobs[i] <= 107

## Solution
## Dynamic Programming
Let's use the bitmap trick to represent subsets of the jobs array. The jobs array of example 2 has a length of 5, so we can use a 5-bit integer to represent any subset of it: each bit indicates whether an element is added to the subset or not. For example:

    0b01011 represents a subset of {1, 2, 7}

With this trick, we can use a single variable to represent a subset of the array.

Define dp[i][m] as the answer(minimum possible maximum working time) of assigning subset "m" to i workers. Create another array sum[] and define sum[m] as the sum of all job times of subset "m".

Base case: when there's only 1 worker, the working time is the sum of all jobs. aka `dp[1][m] = sum[m]`.

For each subset **m**, in the worst case, 1 worker doesn't get any job and the working time is the same as doing the assignment with 1 less worker. Let's try to optimize the answer. we find a smaller subset of **m** and name it **s**. Assign **s** to 1 worker, and recursively assign the rest. Then either the 1 worker has longer working time, or the rest part has longer working time.

    worst case: dp[i][m] = dp[i - 1][m]
    dp[i][m] = max(dp[i - 1][m - s], sum[s])
