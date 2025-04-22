# Topological sorting
Whether the traversal sequence needs to be reversed depends on how the graph is constructed and whether DFS or BFS is used:

* If an edge means "depends on", the course with the **most** indegrees should be taken first
* If an edge means "depended by", the course with the **least** indegrees should be taken first

DFS and BFS visit nodes in different orders:

* DFS(post-order traversal solution) visits nodes with the **most** indegrees first
* BFS visits nodes with the **least** indegrees first

Leetcode Problems:

* [210. Course Schedule II](../../../Leetcode/0210-CourseScheduleII/)
* [310. Minimum Height Trees](../../../Leetcode/0310-MinimumHeightTrees/README.md)
* [1857. Largest Color Value in a Directed Graph(similar to longest path problem)](../../../Leetcode/1857-LargestColorValueInADirectedGraph/README.md)

## DFS
Do Post-order traversal, detect cycle, and collect topoglocal sort result along the way. Similar to cycle detection, we also need `onPath[]` map.

## BFS
Compute the indegree for each node. Enqueue all node with 0 in-degree (meaning they don't depend on other node) and do BFS. For each node we visit, remove its neighbors in-degrees caused by itself (as if we removed the node from the graph). If a node has 0 in-degree now, add it to the queue.

Continue BFS until queue is empty. If all nodes have been visited, there's no cycle in the graph and the sequence of visiting nodes is the topological sort result.
