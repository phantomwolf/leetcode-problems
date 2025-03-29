# 2297. Jump Game VIII
You are given a 0-indexed integer array nums of length n. You are initially standing at index 0. You can jump from index i to index j where i < j if:

* `nums[i] <= nums[j]` and `nums[k] < nums[i]` for all indexes k in the range `i < k < j`, or
* `nums[i] > nums[j]` and `nums[k] >= nums[i]` for all indexes k in the range `i < k < j`.

You are also given an integer array costs of length n where costs[i] denotes the cost of jumping to index i.

Return the minimum cost to jump to the index n - 1.

Example 1:

Input: nums = [3,2,4,4,1], costs = [3,7,6,4,2]
Output: 8
Explanation: You start at index 0.
- Jump to index 2 with a cost of costs[2] = 6.
- Jump to index 4 with a cost of costs[4] = 2.
The total cost is 8. It can be proven that 8 is the minimum cost needed.
Two other possible paths are from index 0 -> 1 -> 4 and index 0 -> 2 -> 3 -> 4.
These have a total cost of 9 and 12, respectively.

Example 2:

Input: nums = [0,1,2], costs = [1,1,1]
Output: 2
Explanation: Start at index 0.
- Jump to index 1 with a cost of costs[1] = 1.
- Jump to index 2 with a cost of costs[2] = 1.
The total cost is 2. Note that you cannot jump directly from index 0 to index 2 because nums[0] <= nums[1].

Constraints:

* n == nums.length == costs.length
* 1 <= n <= 105
* 0 <= nums[i], costs[i] <= 105

## Solution: Dijkstra's Algorithm
Consider the input array as a graph:

* Each index of nums[] is a node.
* costs[] stores the cost/weight to visit each node.
* Edges can be computed from the jumping rules.

Let's see the jumping rules:

1. `nums[i] <= nums[j]` and `nums[k] < nums[i]` for all indexes k in the range `i < k < j`, or
2. `nums[i] > nums[j]` and `nums[k] >= nums[i]` for all indexes k in the range `i < k < j`.

It actually means:

1. Given any nums[i], we can jump to its next greater element nums[j](if any): this is because in case 1, any element between nums[i] and nums[j] is smaller than nums[i]
2. Given any nums[i], we can jump to its next smaller element nums[j](if any): because in case 2, any number between nums[i] and nums[j] is greater than nums[i]

To calculate the **next greater element** and **next smaller element**, we can use the **monotonic stack** technique. For each next greater/smaller element, we add an edge in the graph. Time complexity: O(n). Space complexity: O(n).

Once we created the graph, the problem will become: finding the shortest path from `node 0` to `node nums.size()-1` in a weighted directed graph. We can use the Dijkstra's Algorithm.
