#!/usr/bin/env python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # c[i][j] means the number of unique paths to reach matrix[i][j]
        c = [[1 for j in range(n)] for i in range(m)]   # c[i][0] and c[0][j] should be 1
        for i in range(1, m):
            for j in range(1, n):
                c[i][j] = c[i][j-1] + c[i-1][j]
        return c[m-1][n-1]
