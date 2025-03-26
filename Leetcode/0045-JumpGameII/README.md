# 45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

    Input: nums = [2,3,0,1,4]
    Output: 2

Constraints:

* 1 <= nums.length <= 104
* 0 <= nums[i] <= 1000

## Solution 1: BFS
If we see each index as a node in a graph, and each index we can jump to as adjacent nodes, this problem can be solved by BFS.

## Solution 2: Greedy BFS
Same as Leetcode 55 Jump Game.

Suppose nums = [2,3,1,1,4]. From index 0, we can jump to range [1, 2]. With the BFS solution, node 0 is adjacent to node 1 and 2: we first visit node 0, then visit its neighbors 1 and 2. Then we continue from 1 and 2 to their neighbors.

But is it really necessary to visit all the neighbors?

1. From index 1, we can jump to range [2, 4]
2. From index 2, we can jump to range [2, 3]

To reach the last index with minimum steps, option 1 is clearly better than 2. In fact, there's no need to consider option 2 at all. However, in the BFS solution, both option 1 and 2 are considered.

We can use greedy here. For all the adjacent nodes of index i, we only consider the one which allows us to jump to the farthest index, and continue from there. Meanwhile, we use a variable to track the steps.

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        // [left, right] is the range we can jump to using the next step
        int left = 0, right = 0;
        int steps = 0;
        while (true) {
            if (right == nums.size()-1) {
                return steps;
            }

            int currMax = numeric_limits<int>::min();
            for (int i = left; i <= right; i++) {
                currMax = max(currMax, i+nums[i]);
            }
            // Update range
            if (currMax <= right) {
                // Can't jump farther
                return -1;
            }
            left = right+1;
            right = min(currMax, static_cast<int>(nums.size()-1));
            steps++;
        }
    }
};
```