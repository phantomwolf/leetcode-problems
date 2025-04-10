# Cycle detection and Topological sort of graph
There're 2 ways to doing cycle detection and topological sort: DFS and BFS.

## DFS
Do Post-order traversal, detect cycle and collect topoglocal sort result along the way.

## BFS
Compute the in degree for each vertex. Enqueue all vertice with 0 in-degree (meaning they don't depend on other vertex) and do BFS. For each vertex we visit, remove its neighbors in-degrees caused by itself (as if we removed the vertex from the graph). If a vertex has 0 in-degree now, add it to the queue.

Continue BFS until queue is empty. If all vertice have been visited, there's no cycle in the graph and the sequence of visiting vertice is the topological sort result.

## Leetcode Problems
* 207. Course Schedule
* 210. Course Schedule II
* 310. Minimum Height Trees
* 1857. Largest Color Value in a Directed Graph(similar to longest path problem)
