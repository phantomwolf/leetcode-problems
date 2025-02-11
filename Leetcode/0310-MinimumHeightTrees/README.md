# 310. Minimum Height Trees
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

## Example 1:

![example1](e1.jpg)

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

## Example 2:

![example2](e2.jpg)

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]

## Constraints:

* 1 <= n <= 2 * 104
* edges.length == n - 1
* 0 <= ai, bi < n
* ai != bi
* All the pairs (ai, bi) are distinct.
* The given input is guaranteed to be a tree and there will be no repeated edges.

## Solution
We do something similar to the BFS approach of topological sort (refer to 210 course schedule II).

Since the graph is a tree, there's no cycle in it. First, we define "leaf" vertex as the vertice which only have 1 edge. At the beginning, we add all leaf vertice into queue. Each round, we pop all items which are already in the queue at the beginning of the loop (these items can be seen as in the same layer). When poping vertex, we also remove it from its neighbors edges, which will create new leaf vertice. We add the new leaf vertice into the queue as well.

Repeat the above progress until there're only 2 or less vertice that're not visited.

```java
int remain = n;
while (remain > 2) {
    int size = q.size();
    remain -= size;
    while (size > 0) {
        int leaf = q.remove();
        for (int neighbor : graph[leaf]) {
            // Remove leaf from all its neighbor's edges
            ...
            // New leaf
            if (graph[neighbor].size() == 1) {
                q.add(neighbor);
            }
        }
        size--;
    }
}
```