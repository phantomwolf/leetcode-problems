func alienOrder(words []string) string {
    // Build graph
    graph := make(map[byte][]byte)
    indegrees := make(map[byte]int)
    for _, w := range words {
        for _, c := range w {
            graph[byte(c)] = []byte{}
            indegrees[byte(c)] = 0
        }
    }
    for i := 0; i < len(words)-1; i++ {
        w1, w2 := words[i], words[i+1]
        j := 0
        for j < len(w1) && j < len(w2) && w1[j] == w2[j] {
            j++
        }
        if j == len(w1) || j == len(w2) {
            if len(w1) > len(w2) {
                return ""
            }
            continue
        }
        // Add edge
        graph[w1[j]] = append(graph[w1[j]], w2[j])
        indegrees[w2[j]]++
    }
    // BFS topological sort
    result := []byte{}
    queue := list.New()
    nodesVisited := 0
    for v, d := range indegrees {
        if d == 0 {
            queue.PushBack(v)
        }
    }
    for queue.Len() > 0 {
        elem := queue.Front()
        queue.Remove(elem)
        node := elem.Value.(byte)
        nodesVisited++
        result = append(result, node)
        // Neighbors
        for _, v := range graph[node] {
            indegrees[v]--
            if indegrees[v] == 0 {
                queue.PushBack(v)
            }
        }
    }
    // Check if all nodes are visited
    if nodesVisited < len(graph) {
        // Cycle detected
        return ""
    }
    return string(result)
}