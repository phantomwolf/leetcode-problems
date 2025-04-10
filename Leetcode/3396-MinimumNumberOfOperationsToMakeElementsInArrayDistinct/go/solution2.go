func minimumOperations(nums []int) int {
	seen := make([]bool, 101)
	for i := len(nums) - 1; i >= 0; i-- {
		if seen[nums[i]] {
			return int(math.Ceil(float64(i+1) / 3))
		}
		seen[nums[i]] = true
	}
	return 0
}
