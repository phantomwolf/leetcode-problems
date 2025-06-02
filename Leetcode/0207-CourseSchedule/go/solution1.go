func canFinish(numCourses int, prerequisites [][]int) bool {
    // Build graph
    graph := make([][]int, numCourses)
    for _, p := range prerequisites {
        from, to := p[0], p[1]
        graph[from] = append(graph[from], to)
    }
    // DFS cycle detection
    visited := make([]bool, numCourses)
    onPath := make([]bool, numCourses)
    for v := 0; v < numCourses; v++ {
        if hasCycle(graph, v, visited, onPath) {
            return false
        }
    }
    return true
}

func hasCycle(graph [][]int, node int, visited []bool, onPath []bool) bool {
    if onPath[node] {
        // node already on path. Cycle detected.
        return true
    }
    if visited[node] {
        // node already visited. Skip.
        return false
    }
    // Mark as visited
    visited[node] = true
    // Add to path
    onPath[node] = true
    // Visit neighbors
    for _, v := range graph[node] {
        if hasCycle(graph, v, visited, onPath) {
            return true
        }
    }
    // Remove from path
    onPath[node] = false
    return false
}