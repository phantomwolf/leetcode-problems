# 2320. Count Number of Ways to Place Houses
There is a street with n * 2 plots, where there are n plots on each side of the street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.

Return the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.

Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on the ith plot on the other side of the street.

Example 1:

Input: n = 1
Output: 4
Explanation: 
Possible arrangements:

1. All plots are empty.
2. A house is placed on one side of the street.
3. A house is placed on the other side of the street.
4. Two houses are placed, one on each side of the street.

Example 2:

Input: n = 2
Output: 9
Explanation: The 9 possible arrangements are shown in the diagram above.

Constraints:

* 1 <= n <= 104

## Solution 1: Dynamic Programming
Each side of the street is independent, and doesn't affect each other. So we can calculate the number of ways to place houses on one side, then multiple them.

Define dp[i] as the number of ways to place houses on **one side**, when there're i plots. For each plot, we have two choices:

* If we place a house on i-th plot, since we can't place a house on i-1, there're `dp[i-2]` ways to place houses on previous plots
* If we don't place a house on i-th plot, the result will be the same as placing houses on i-1 plots: `dp[i-1]`.

Sum them up: `dp[i] = dp[i-1] + dp[i-2]`.

This is basically fibonacci sequence.

## Solution 2: Fibonacci Sequence
We already know it's a fibonacci sequence. Just use 3 variables to calculate the result.