# UnionFind并查集
并查集（Union Find）结构是 二叉树结构 的衍生，用于高效解决无向图的连通性问题，可以在 O(1) 时间内合并两个连通分量，在 O(1) 时间内查询两个节点是否连通，在 O(1) 时间内查询连通分量的数量。

并查集（Union Find）结构提供如下 API：

```java
class UF {
    // 初始化并查集，包含 n 个节点，时间复杂度 O(n)
    public UF(int n);

    // 连接节点 p 和节点 q，时间复杂度 O(1)
    public void union(int p, int q);

    // 查询节点 p 和节点 q 是否连通（是否在同一个连通分量内），时间复杂度 O(1)
    public boolean connected(int p, int q);

    // 查询当前的连通分量数量，时间复杂度 O(1)
    public int count();
}
```

https://labuladong.online/algo/data-structure-basic/union-find-basic/