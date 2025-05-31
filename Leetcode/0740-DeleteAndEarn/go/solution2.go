func deleteAndEarn(nums []int) int {
	// Counting sort
	points := make([]int, int(1e4+1))
	n := 0
	for _, v := range nums {
		points[v] += v
		n = max(n, v)
	}
	n++

	if n == 1 {
		return points[n-1]
	}

	dp_i1, dp_i2 := 0, 0
	dp_i := 0
	for i := n - 1; i >= 0; i-- {
		dp_i = max(points[i]+dp_i2, dp_i1)
		dp_i2 = dp_i1
		dp_i1 = dp_i
	}
	return dp_i
}