package com.snowwolf;

import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[][] obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
        Solution solution = new Solution();
        int count = solution.uniquePathsWithObstacles(obstacleGrid);
        System.out.printf("Unique paths: %d%n", count);
    }
}