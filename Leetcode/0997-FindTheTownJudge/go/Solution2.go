func findJudge(n int, trust [][]int) int {
	// Build a directed graph based on the following rule: if A trusts B, there's a edge from A to B
	// Then the town judge should have in degree of n and out degree of 0.
	// score[i] = indegree[i] - outdegree[i]
	score := make([]int, n+1)
	for _, v := range trust {
		from, to := v[0], v[1]
		score[from]--
		score[to]++
	}
	// Find the town judge
	for i := 1; i <= n; i++ {
		if score[i] == n-1 {
			return i
		}
	}
	return -1
}