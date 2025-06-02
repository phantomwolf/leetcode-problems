import (
    "container/list"
    "slices"
)

func findOrder(numCourses int, prerequisites [][]int) []int {
    var result []int
    // Build graph
    graph := make([][]int, numCourses)
    indegrees := make([]int, numCourses)
    for _, p := range prerequisites {
        graph[p[0]] = append(graph[p[0]], p[1])
        indegrees[p[1]]++
    }
    // BFS topological sort
    queue := list.New()
    for v := 0; v < numCourses; v++ {
        if indegrees[v] == 0 {
            queue.PushBack(v)
        }
    }
    nodesVisited := 0
    for queue.Len() > 0 {
        elem := queue.Front()
        queue.Remove(elem)
        node := elem.Value.(int)
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
    if nodesVisited != numCourses {
        // Cycle detected
        return []int{}
    }
    // Reverse
    slices.Reverse(result)
    return result
}