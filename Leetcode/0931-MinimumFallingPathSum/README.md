# 931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

## Example 1

```
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
```

## Example 2

```
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

## Constraints

- n == matrix.length == matrix[i].length
- 1 <= n <= 100
- -100 <= matrix[i][j] <= 100

## Solution: Dynamic programming
Define dp[i][j] as the min sum of any falling path that ends at matrix[i][j].

Base case: `dp[0][j] = matrix[0][j]`

Optimal substructure: `dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1])`

## Space-optimized DP solution
观察DP Solution，可知求dp[i][j]时，我们只需要上一行的值：dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]。

创建一维数组dp[]：dp[i-1][j-1]为dp[j-1]已被覆盖掉的旧值，所以我们需要一个变量来保存这个旧值；dp[i-1][j]即dp[j]未被覆盖前的值；dp[i-1][j+1]即dp[j+1]，因为其在循环的下一步才会被覆盖，可以直接用。