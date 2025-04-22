import (
	"container/list"
	"math"
)

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	// Build graph
	graph := make([][][]int, n)
	for _, flight := range flights {
		from, to, price := flight[0], flight[1], flight[2]
		graph[from] = append(graph[from], []int{to, price})
	}
	// BFS
	dist := make([]int, n)
	for i := range dist {
		dist[i] = math.MaxInt
	}
	dist[src] = 0
	queue := list.New()
	queue.PushBack([]int{src, dist[src]})
	stops := 0
	for queue.Len() > 0 && stops <= k {
		size := queue.Len()
		for i := 0; i < size; i++ {
			tuple := queue.Front().Value.([]int)
			queue.Remove(queue.Front())
			u, d := tuple[0], tuple[1]
			// Neighbors
			for _, tuple := range graph[u] {
				v, price := tuple[0], tuple[1]
				if d+price < dist[v] {
					dist[v] = d + price
					queue.PushBack([]int{v, dist[v]})
				}
			}
		}
		stops++
	}
	// Check if it's possible to reach destination
	if dist[dst] == math.MaxInt {
		return -1
	}
	return dist[dst]
}