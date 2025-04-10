# Graph
Typical graph coding problems by importance:

1. DFS, BFS
2. Topological sorting
   1. Course schedule
   2. Minimum Height Tree
   3. Longest path(1857. Largest Color Value in a Directed Graph)
3. Cycle detection
4. Shortest path: Dijkstra's Algorithm

## DFS

## BFS

## Cycle detection
To detect cycles in a graph, I usually prefer DFS because it doesn't require a queue.

Time complexity: O(V*E)
Space complexity: O(V)

### Directed Graph
Compared to a typical DFS, cycle detection algorithm introduces another hash map(or array if node ids are numbers) named `onPath` to record if a specific node is on current traversal path. When we visit a node, set `onPath[node] = true`; when we leave a node, set `onPath[node] = false`. If we're trying to visit a node, but it's already on path, this means: we've reached that node before, but there's a cycle in the graph which leads us back to the node again. In other words, a cycle has been detected.

`onPath` map doesn't conflict with `visited` map. In fact, they're both needed:

* `onPath` records if a node is on current DFS traversal path. If yes, a cycle has been detected.
* `visited` records if a node has been visited before. If yes, simply skip it.

Note that `onPath` needs to be checked before `visited`(because if a node is onPath, clearly it was visited before).

```go

```

### Undirected Graph
Undirected graph is a bit more complicated than directed graph, becuase it contains "trivial cycles" like `A -> B -> A`. For example: when we're visiting A, of course `visited[A] = true` and `onPath[A] = true`. Next, we proceed to visit B. However, when we're visiting all neighbors of B, we'll find A is a neighbor of B as well, and A is already on path. But it's not actually a cycle, it's just an undirected edge. **We need a way to skip A when visiting all neighbors of B.**

To achieve this, we add a `prevNode` parameter to the DFS function, which is the previous node we've visited. When we visit B, `prevNode = A`. When visiting all neighbors of B, we skip `prevNode = A` to avoid trivial cycles.

```go
func hasCycle(graph [][]int, prevNode int, node int, onPath []bool, visited []bool) bool {
    if onPath[node] {
        // node already on path. Cycle detected
        return true
    }
    if visited[node] {
        // node already visited. Skip.
        return false
    }
    visited[node] = true
    onPath[node] = true
    // Neighbors
    for _, v := range graph[node] {
        if v == prevNode {
            // Ignore previous node on the path
            continue
        }
        if hasCycle(graph, node, v, onPath, visited) {
            return true
        }
    }
    onPath[node] = false
    return false
}
```

## Topological sort
Topological sort can be done using DFS or BFS.
