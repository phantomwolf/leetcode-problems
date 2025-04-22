// DFS
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
