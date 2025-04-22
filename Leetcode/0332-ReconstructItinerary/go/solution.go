func findItinerary(tickets [][]string) []string {
	// Build graph
	graph := map[string][]string{}
	for _, ticket := range tickets {
		graph[ticket[0]] = append(graph[ticket[0]], ticket[1])
	}
	// Sort destinations by reverse lexical order
	for _, adj := range graph {
		sort.Slice(adj, func(a, b int) bool { return adj[a] > adj[b] })
	}
	path := []string{}
	dfs(graph, "JFK", &path)
	// Reverse path
	i, j := 0, len(path)-1
	for i < j {
		path[i], path[j] = path[j], path[i]
		i++
		j--
	}
	return path
}

func dfs(graph map[string][]string, node string, path *[]string) {
	for len(graph[node]) > 0 {
		n := len(graph[node])
		next := graph[node][n-1]
		graph[node] = graph[node][:n-1]
		dfs(graph, next, path)
	}
	// After visiting all edges from node, append it to path
	(*path) = append(*path, node)
}