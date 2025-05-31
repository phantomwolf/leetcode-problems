func countHousePlacements(n int) int {
	a := 1
	b := 1
	var c int
	for i := 1; i <= n; i++ {
		c = (a + b) % (1e9 + 7)
		a = b
		b = c
	}
	return int((c * c) % (7 + 1e9))
}