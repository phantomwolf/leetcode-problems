# Dijkstra's Algorithm
https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/

Dijkstra's Algorithm is similar to BFS, but with a few differences:

- dist[] array: Instead of visited[] array, use a dist[] array to store the distance from source node to each node. `dist[]` is initialized to INT_MAX. `dist[src]` is 0.
- **Priority Queue**: Instead of ordinary queue, create a priority_queue(min heap) which stores `(dist[v], v)` pairs. `dist[v]` is the distance to node v and is used to sort the priority queue. `v` is the node number.
- Only push a node into queue when visiting `v` through `u` generates a shorter `dist[v]`

```java
    // Prints shortest paths from src to all other vertices
    static void shortestPath(List<List<Pair<Integer, Integer>>> adj, int V, int src) {
        // Create a priority queue to store vertices that are being preprocessed.
        PriorityQueue<Pair<Integer, Integer> > pq  = new PriorityQueue<>(Comparator.comparingInt(Pair::getFirst));
        // Create a list for distances and initialize all distances as infinite (INF)
        List<Integer> dist = new ArrayList<>(Collections.nCopies(V, INF));
        // Insert source itself in priority queue and initialize its distance as 0.
        pq.add(new Pair<>(0, src));
        dist.set(src, 0);
        // Looping till priority queue becomes empty (or all distances are not finalized)
        while (!pq.isEmpty()) {
            // The first vertex in pair is the minimum distance vertex, extract it from priority queue.
            int u = pq.peek().getSecond();
            pq.pop();
            // Get all adjacent of u.
            for (Pair<Integer, Integer> x : adj.get(u)) {
                // Get vertex label and weight of current adjacent of u.
                int v = x.getFirst();
                int weight = x.getSecond();
                // If there is a shorter path to v through u.
                if (dist.get(v) > dist.get(u) + weight) {
                    // Updating distance of v
                    dist.set(v, dist.get(u) + weight);
                    pq.add(new Pair<>(dist.get(v), v));
                }
            }
        }
        // Print shortest distances stored in dist[]
        System.out.println("Vertex \tDistance from Source");
        for (int i = 0; i < V; i++) {
            System.out.printf("%d \t\t %d\n", i, dist.get(i));
        }
    }
```

## Leetcode Problems
See the following leetcode problems

* [Leetcode/0505-TheMazeII](../../../Leetcode/0505-TheMazeII/README.md)
* [Leetcode/2297-JumpGameVIII](../../../Leetcode/2297-JumpGameVIII/README.md)
