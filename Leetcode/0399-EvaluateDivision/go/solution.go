package main

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	graph := make(map[string]map[string]float64)
	for i, e := range equations {
		from, to := e[0], e[1]
		// add edge for equation: from / to
		if graph[from] == nil {
			graph[from] = make(map[string]float64)
		}
		graph[from][to] = values[i]
		// add edge for equation: to / from
		if graph[to] == nil {
			graph[to] = make(map[string]float64)
		}
		graph[to][from] = 1 / values[i]
	}

	res := []float64{}
	for _, q := range queries {
		visited := make(map[string]bool)
		ret := dfs(graph, q, q[0], 1.0, visited)
		res = append(res, ret)
	}
	return res
}

// Use dfs to find a path between 2 nodes, calculating the result along the way
func dfs(graph map[string]map[string]float64, query []string, node string, value float64, visited map[string]bool) float64 {
	// If node doesn't exist in graph, return -1
	if _, ok := graph[node]; !ok {
		return -1.0
	}
	// If node is the destination, return result
	if query[1] == node {
		return value
	}
	// If node is already visited, return -1 to continue searching another path
	if visited[node] {
		return -1.0
	}
	visited[node] = true
	// Neighbors
	for n, v := range graph[node] {
		ret := dfs(graph, query, n, value*v, visited)
		// If any path returns a result, return it
		if ret >= 0 {
			return ret
		}
	}
	// Can't reach query[1] from this node
	return -1.0
}
