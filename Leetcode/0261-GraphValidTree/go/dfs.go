func validTree(n int, edges [][]int) bool {
	// Build graph
	graph := make([][]int, n)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}
	visited := make([]bool, n)
	onPath := make([]bool, n)
	nodesVisited := 0
	if hasCycle(graph, 0, -1, visited, onPath, &nodesVisited) {
		return false
	}
	// Check if all nodes are visited
	if nodesVisited < n {
		// Not every node is connected
		return false
	}
	return true
}

// Returns true if any cycle exists in the graph
func hasCycle(graph [][]int, node int, parent int, visited []bool, onPath []bool, nodesVisited *int) bool {
	if onPath[node] {
		// Cycle detected
		return true
	}
	if visited[node] {
		// Skip visited node
		return false
	}
	visited[node] = true
	onPath[node] = true
	(*nodesVisited)++
	// Neighbors
	for _, v := range graph[node] {
		if parent == v {
			continue
		}
		if hasCycle(graph, v, node, visited, onPath, nodesVisited) {
			return true
		}
	}
	return false
}