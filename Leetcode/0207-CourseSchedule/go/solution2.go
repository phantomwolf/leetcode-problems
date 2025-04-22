package main

import "container/list"

func canFinish(numCourses int, prerequisites [][]int) bool {
	// Build graph and indegrees
	indegrees := make([]int, numCourses)
	graph := make([][]int, numCourses)
	for _, edge := range prerequisites {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		indegrees[edge[1]]++
	}

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
		// Remember the number of nodes visited
		nodesVisited++
		// Update indegrees
		for _, next := range graph[elem.Value.(int)] {
			indegrees[next]--
			if indegrees[next] == 0 {
				queue.PushBack(next)
			}
		}
	}
	if nodesVisited < numCourses {
		return false
	}
	return true
}
