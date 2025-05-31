func deleteAndEarn(nums []int) int {
	// Counting sort
	points := make([]int, int(1e4+1))
	n := 0 // maxNumber + 1
	for _, v := range nums {
		points[v] += v
		n = max(n, v)
	}
	n++

	dp := make([]int, n)
	// Base case
	dp[n-1] = points[n-1]
	dp[n-2] = max(points[n-2], dp[n-1])
	for i := n - 3; i >= 0; i-- {
		dp[i] = max(points[i]+dp[i+2], dp[i+1])
	}
	return dp[0]
}