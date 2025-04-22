package main

func canFinish(numCourses int, prerequisites [][]int) bool {
	// Build the graph
	graph := make([][]int, numCourses)
	for _, edge := range prerequisites {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
	}
	// DFS
	visited := make([]bool, numCourses)
	onPath := make([]bool, numCourses)
	for i := range graph {
		res := dfs(graph, i, visited, onPath)
		if !res {
			return false
		}
	}
	return true
}

// Returns true if can finish
func dfs(graph [][]int, node int, visited []bool, onPath []bool) bool {
	if onPath[node] {
		// Node already on path. Cycle detected. Can't finish
		return false
	}
	if visited[node] {
		// Node already visited. Skip it
		return true
	}

	visited[node] = true
	onPath[node] = true
	// Visit neighbors
	for _, next := range graph[node] {
		res := dfs(graph, next, visited, onPath)
		if !res {
			return false
		}
	}
	onPath[node] = false
	return true
}
