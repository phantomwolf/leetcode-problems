# 1857. Largest Color Value in a Directed Graph
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.

Constraints:

* n == colors.length
* m == edges.length
* 1 <= n <= 105
* 0 <= m <= 105
* colors consists of lowercase English letters.
* 0 <= aj, bj < n

## Solution: longest path
The problem is similar to finding the longest path in a acyclic graph, except different colors in the path are calculated separately.

Longest path problem: the longest path(if exists) will always start from a node whose in-degree is 0. We can do topological sorting(no need to collect the results) and calculate the longest path ending at each node along the way.

For this specific problem, instead of calculating the path length, we calculate the max possible color value for each color of each node. We don't really care which path leads to the max color value, as the problem only asks for the max color value of any color.

Key points:

* Use a array `color[node][color]` to record the max color value for `color` of `node`.
* When adding neighboring nodes to queue, if there's an edge from u to v, let `count[v][color] = max(count[v][color], count[u][color])`. This might be counter-intuitive, as we didn't count in the node's own color, but wel'll do so later when popping it from the queue.
* When visiting a node(popping it from queue), count in the node's own color by incrementing `count[v][color]`.
