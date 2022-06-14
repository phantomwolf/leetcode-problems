# 63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

## 解答
此题与62 Unique Paths类似，只是增加了障碍。当一个位置上有障碍时，到达该位置的路径数为0。

空间优化的DP方案：

观察普通的DP解法可知dp[i][j] = dp[i-1][j] + dp[i][j-1]，只会用到相邻的dp数组中的值，因此没必要创建整个dp数组，我们将i坐标省略掉，令dp[j]为二维dp[][]数组中的最近一行，可知dp[j] = dp[j] + dp[j-1]。