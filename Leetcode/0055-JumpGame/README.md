# 55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:

* 1 <= nums.length <= 104
* 0 <= nums[i] <= 105

## Solution 1: DFS
If we see each index as a node in a graph, this can be solved by DFS. In example 1, nums[0] = 2, which means we can jump to [1, 2]. In other words, node 0 is adjacent with node 1 and 2.

Use DFS to visit the nodes. If we can reach the last index nums.size()-1, it means we can jump to the last index.

## Solution 2: BFS
Similar to solution 1, but this time we use BFS.

## Solution 3: Dynamic Programming 
Define dp[i] as the farthest index can be reached from any position in range [0, i]. In example 1, nums[1] = 3, nums[2] = 1, dp[2] = 4.

Base case: we can reach range [0, nums[0]] from index 0.

For each i > 0, if there's any j which makes `dp[j] >= i, j ∈ [0, i-1]`, it means i can be reached. In this case, `dp[i] = max(max(dp[j]), i + nums[i]), j ∈ [0, i-1]`:


```java
for (int i = 1; i < nums.length; i++) {
    int max = Integer.MIN_VALUE;
    for (int j = i - 1; j >= 0; j--) {
        max = Math.max(max, dp[j]);
    }
    if (max < i) {
        // Impossible to reach i
        return false;
    }
    // If we can reach i
    dp[i] = Math.max(max, i + nums[i]);
}
```

Time complexity: O(n^2). Space complexity: O(n).

**Optimization**: The inner loop is just for calculating the largest value of `dp[0], dp[1], ..., dp[i-1]`. We can use a variable to track the largest value of dp[j]. Thus:

```java
int currMax = dp[0];
for (int i = 1; i < nums.length; i++) {
    currMax = Math.max(dp[i - 1], currMax);
    if (currMax < i) {
        return false;
    }
    dp[i] = Math.max(currMax, i + nums[i]);
    if (dp[i] >= nums.length - 1) {
        return true;
    }
}
```

Time complexity: O(n). Space complexity: O(n).

**Further optimization**: we can see within the loop, only dp[i-1] and dp[i] are involved. This means we don't need an dp array to store the values. After further optimization, this solution will become solution 4: Greedy Solution.

## Solution 4: Greedy Solution
Define `currMax` as the farthest index we can reach from the positions we've scanned so far.

At the beginning, the farthest index we can reach is `currMax = 0`.

From 0, we can reach [1, nums[0]], so we continue scanning to `currMax = nums[0]`. Meanwhile, we keep updating currMax as we scan new elements.

If at any given time, currMax >= lastIndex, it means we can jump to the last index.