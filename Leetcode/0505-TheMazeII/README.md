# 505. The Maze II
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).

 


## Example 1:

![The Maze](../0490-TheMaze/maze1-1-grid.jpg)

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12

Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

## Constraints:

* m == maze.length
* n == maze[i].length
* 1 <= m, n <= 100
* maze[i][j] is 0 or 1.
* start.length == 2
* destination.length == 2
* 0 <= startrow, destinationrow < m
* 0 <= startcol, destinationcol < n
* Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
* The maze contains at least 2 empty spaces.

# Solution 1: BFS
The maze is actually a weighted graph. In example 1, the starting point (0, 4) has edges to nodes (0, 3) and (2, 4):

* To reach (0, 3), the ball needs to move left for 1 space: this edge has a weight of 1
* To reach (2, 4), the ball needs to move down for 2 spaces: this edge has a weight of 2

However, in BFS, these 2 edges are reached at the same time. Both (0, 3) and (2, 4) are enqueued at the same time. Just because we visited the node first in our program, it doesn't mean the path we found is the shortest one.

Take a look at the following graph:

```
A---(3)-----B
|           |
\-(1)-C--(1)/
```

A normal BFS will take the path directly from A to B, marking B as seen, and A to C, marking C as seen. However, the shortest path to B is through C and ordinary BFS fails to see this.

To solve this, we need to make some modifications to normal BFS:

* The visited[][] array is removed because it guarantees a node is only visited once. In the graph above, we have to visit B twice to get the shortest path.
* A distance[][] array is introduced to record the shortest path to each node.
* We only add a neighboring node to queue if this generates a shorter path(don't forget to update distance[][]).

Since we only add a node to queue if it generates a shorter path, we don't need to worry about circles even if visited[][] is gone.

# Solution 2: Dijkstra Algorithm
Since the maze is a weighted graph, it makes sense to use Dijkstra's algorithm. Compared with an ordinary BFS, Dijkstra differs in the following ways:

* Instead of a FIFO queue, a minimum priority queue is used.
* No need to use visited[][] array, as we might visit a node multiple times. Instead, we need a distance[][] array.

To create a mim-heap in Java, there's a convenient syntax. Just pass a lambda function to the constructor of PriorityQueue:

```java
PriorityQueue<SimpleEntry<int[], Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
```

