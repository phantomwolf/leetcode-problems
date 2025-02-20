func findJudge(n int, trust [][]int) int {
	// Build a directed graph based on the following rule: if A trusts B, there's a edge from A to B
	// Then the town judge should have in degree of n and out degree of 0.
	indegrees := make([]int, n+1)
	outdegrees := make([]int, n+1)
	for _, v := range trust {
		from, to := v[0], v[1]
		outdegrees[from]++
		indegrees[to]++
	}
	// Find the town judge
	for i := 1; i <= n; i++ {
		if indegrees[i] == n-1 && outdegrees[i] == 0 {
			return i
		}
	}
	return -1
}