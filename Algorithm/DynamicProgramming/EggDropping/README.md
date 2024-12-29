# Egg dropping puzzle
Leetcode 887. Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

    Input: k = 1, n = 2
    Output: 2
    Explanation:
    Drop the egg from floor 1. If it breaks, we know that f = 0.
    Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
    If it does not break, then we know f = 2.
    Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:

    Input: k = 2, n = 6
    Output: 3

Example 3:

    Input: k = 3, n = 14
    Output: 4

Constraints:

* 1 <= k <= 100
* 1 <= n <= 104

## Solution: Dynamic programming
设dp[i][j]为在最坏情况下，用i个鸡蛋探测j层楼所需的最小次数。基本情况：

* 当`i=1`时，只有1个鸡蛋，只有一种探测的方法：从第1层开始，逐层向上探测，最坏情况下需要j次探测。即`dp[1][j] = j`
* 当`j=0`时，楼层数为0，需要的探测次数为0。即`dp[i][0] = 0`
* 当`j=1`时，只有1个楼层，无论鸡蛋有多少（只要不为0），都只需要探测一次。即`dp[i][1] = 1`
* 注意，dp[0][j], j > 0是无效的，不可能完成探测

对于`dp[i][j], i >= 2, j >= 2`，令`x ∈ [1,j]`假设我们从第`x`层楼丢下鸡蛋（这算一次探测），可能会出现两种情况：鸡蛋碎掉，或者没碎。如果鸡蛋碎掉，目标楼层肯定比x要低，接下来我们需要用`i-1`个鸡蛋探测下面的`x-1`层楼，即`dp[i][j] = 1 + dp[i-1][x-1]`；如果鸡蛋没碎，目标楼层肯定比x要高，由于总共有n层楼，所以还剩下n-x层需要探测，接下来我们需要用`i`个鸡蛋来探测上面的`n-x`层楼，即`dp[i][j] = 1 + dp[i][n-x]`。我们不知道哪种情况会发生，根据题目要求取最坏的情况，因此如果从第x层楼丢下鸡蛋，用`i`个鸡蛋探测`j`层楼在最坏情况下需要`1 + max(dp[i-1][x-1], dp[i][n-x])`次探测。

接下来，我们需要找出最优的`x`，令`dp[i][j]`最小。最简单的方法就是写一个循环，令x从1到j循环，依次求值，并取最小的结果，即

    dp[i][j] = min(
        1 + max(dp[i-1][x1-1], dp[i][n-x1]),
        1 + max(dp[i-1][x2-1], dp[i][n-x2]),
        ...
    ), 其中x ∈ [1,j]

Time complexity: O(KN^2), space complexity: O(KN)

## Solution: Dynamic programming with binary search
上一个解法中，为了寻找最优的`x`，我们使用一个循环，线性地寻找。一个更好的办法是使用二分查找。

我们已知楼层数越多，需要的探测次数越多，因此随着`x`递增，`dp[i-1][x-1]`增大，`dp[i][n-x]`减少。我们要求的是最小的`max(dp[i-1][x-1], dp[i][n-x])`，所以当两者相交的时候，结果最优。因此我们使用二分搜索：`x ∈ [1,j]`，若两者相当，那么这肯定就是最优的x；若`dp[i-1][x-1] < dp[i][n-x]`，就继续向右边搜索；若`dp[i-1][x-1] > dp[i][n-x]`，就向左边搜索。

Time complexity: O(KNlogN), space complexity: O(KN)
