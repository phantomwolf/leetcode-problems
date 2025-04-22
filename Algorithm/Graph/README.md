# Graph
Typical graph coding problems by importance:

1. DFS, BFS
2. Cycle detection
3. Topological sorting
4. Shortest path: Dijkstra's Algorithm, or BFS

## Less frequent problems
### Eulerian Path 

* Leetcode problem: 332. Reconstruct Itinerary

Eulerian Path (also called Eulerian Trail) is a path in a finite graph that visits every edge exactly once. There is a concept named Eulerian Circuits (or Eulerian Cycle) that restricts Eulerian Path conditions further. It is still an Eulerian Path and it starts and ends at the same vertex.

There are Euler Path conditions that graphs must have:
For an undirected graph

* Every vertex should have an even degree or only two vertices should have odd degrees.

For a directed graph

* Each vertex should have the same in-degree and out-degree except for two of them.
* One of these vertex will be the start vertex which has one more out-going edge than in-going edges. The other one will be the end vertex which has one more in-going edge than out-going edges.

The following conditions determine whether a graph has an Eulerian Cycle or not on top of Eulerian Path conditions:
For an undirected graph

* Each vertex should have an even degree.

For a directed graph

* Every vertex should have equal in-degree and out-degree edges.

**Hierholzer’s Algorithm** can build an Eulerian Path. It works similar to a post-order traversal: visiting all its neighbors before visiting a node

1. Choose any arbitrary vertex as a starting point.
2. Remove an outging edge, and follow it to recursively traverse its neighbors.
3. Repeat 2 until there's no outgoing edges for this node
4. Append this node to the path array
5. After all nodes have been visited, reverse the path array
