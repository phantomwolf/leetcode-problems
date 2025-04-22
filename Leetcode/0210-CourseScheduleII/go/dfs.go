func findOrder(numCourses int, prerequisites [][]int) []int {
	// Build graph
	graph := make([][]int, numCourses)
	for _, edge := range prerequisites {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
	}
	// DFS
	visited := make([]bool, numCourses)
	onPath := make([]bool, numCourses)
	res := []int{}
	for i := 0; i < numCourses; i++ {
		if !dfs(graph, i, visited, onPath, &res) {
			// Cycle detected
			return []int{}
		}
	}
	return res
}

// If returns false, topological sort can't be done because there's a cycle
func dfs(graph [][]int, node int, visited []bool, onPath []bool, res *[]int) bool {
	if onPath[node] {
		// Cycle detected
		return false
	}
	if visited[node] {
		return true
	}
	visited[node] = true
	onPath[node] = true
	// Visit neighbors
	for _, next := range graph[node] {
		if !dfs(graph, next, visited, onPath, res) {
			return false
		}
	}
	onPath[node] = false
	// After visiting all neighbors, add node to result
	*res = append(*res, node)
	return true
}