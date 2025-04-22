import "container/list"

func findOrder(numCourses int, prerequisites [][]int) []int {
	// Build graph and calculate indegrees
	graph := make([][]int, numCourses)
	indegree := make([]int, numCourses)
	for _, edge := range prerequisites {
		// Edge means "depended by"
		graph[edge[1]] = append(graph[edge[1]], edge[0])
		indegree[edge[0]]++
	}
	// BFS
	queue := list.New()
	for v := 0; v < numCourses; v++ {
		if indegree[v] == 0 {
			queue.PushBack(v)
		}
	}
	nodesVisited := 0
	res := []int{}
	for queue.Len() > 0 {
		node := queue.Front().Value.(int)
		queue.Remove(queue.Front())
		nodesVisited++
		res = append(res, node)
		// Remove indegrees
		for _, v := range graph[node] {
			indegree[v]--
			if indegree[v] == 0 {
				queue.PushBack(v)
			}
		}
	}
	if nodesVisited < numCourses {
		return []int{}
	}
	return res
}
