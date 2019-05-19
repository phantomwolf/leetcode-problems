#!/usr/bin/env python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0
        c = [[0 for j in range(len(obstacleGrid[0]))] for i in range(len(obstacleGrid))]
        c[0][0] = 1
        for i in range(1, len(obstacleGrid)):
            if obstacleGrid[i][0] == 1:
                c[i][0] = 0
            else:
                c[i][0] = c[i-1][0]
        for j in range(1, len(obstacleGrid[0])):
            if obstacleGrid[0][j] == 1:
                c[0][j] = 0
            else:
                c[0][j] = c[0][j-1]
        for i in range(1, len(obstacleGrid)):
            for j in range(1, len(obstacleGrid[0])):
                if obstacleGrid[i][j] == 1:
                    c[i][j] = 0
                else:
                    c[i][j] = c[i-1][j] + c[i][j-1]
        return c[-1][-1]

