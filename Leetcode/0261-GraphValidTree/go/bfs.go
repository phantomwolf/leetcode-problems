import "container/list"

type Pair struct {
	Node   int
	Parent int
}

func validTree(n int, edges [][]int) bool {
	// Build graph
	graph := make([][]int, n)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}
	// BFS
	visited := make([]bool, n)
	queue := list.New()
	queue.PushBack(&Pair{Node: 0, Parent: -1})
	visited[0] = true
	nodesVisited := 0
	for queue.Len() > 0 {
		pair := queue.Front().Value.(*Pair)
		queue.Remove(queue.Front())
		nodesVisited++
		// Visit neighbors
		for _, v := range graph[pair.Node] {
			if pair.Parent == v {
				// Ignore parent
				continue
			}
			if visited[v] {
				// Cycle detected
				return false
			}
			visited[v] = true
			queue.PushBack(&Pair{Node: v, Parent: pair.Node})
		}
	}
	// Check if all nodes have been visited
	if nodesVisited < n {
		return false
	}
	return true
}
