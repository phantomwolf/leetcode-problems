package main

type Node struct {
	x int
	y int
}

type UnionFind struct {
	parent map[Node]Node
	count  int
}

func NewUnionFind(m, n int) *UnionFind {
	uf := &UnionFind{
		parent: map[Node]Node{},
		count:  m * n,
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			n := Node{x: i, y: j}
			uf.parent[n] = n
		}
	}
	return uf
}

func (uf *UnionFind) Union(a Node, b Node) {
	aParent := uf.Find(a)
	bParent := uf.Find(b)
	if aParent != bParent {
		uf.parent[aParent] = bParent
		uf.count--
	}
}

func (uf *UnionFind) Find(n Node) Node {
	// Path compression
	if uf.parent[n] != n {
		uf.parent[n] = uf.Find(uf.parent[n])
	}
	return uf.parent[n]
}

func (uf *UnionFind) Count() int {
	return uf.count
}

func numIslands(grid [][]byte) int {
	countZero := 0
	uf := NewUnionFind(len(grid), len(grid[0]))
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '0' {
				countZero++
				continue
			}
			v := Node{x: i, y: j}
			neighbors := []Node{
				Node{x: i - 1, y: j},
				Node{x: i, y: j - 1},
			}
			for _, n := range neighbors {
				if n.x >= 0 && n.x < len(grid) && n.y >= 0 && n.y < len(grid[0]) && grid[n.x][n.y] == '1' {
					//fmt.Printf("Union: (%d,%d) <=> (%d,%d)\n", v.x, v.y, n.x, n.y)
					uf.Union(v, n)
				}
			}
		}
	}
	return uf.Count() - countZero
}
