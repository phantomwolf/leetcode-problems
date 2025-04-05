package solution1

func numIslands(grid [][]byte) int {
	count := 0
	for x := 0; x < len(grid); x++ {
		for y := 0; y < len(grid[0]); y++ {
			if grid[x][y] == '1' {
				count++
				dfs(grid, x, y)
			}
		}
	}
	return count
}

func dfs(grid [][]byte, x, y int) {
	grid[x][y] = '2'
	dirs := [][]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}
	// Visit adjacent nodes
	for _, dir := range dirs {
		i := x + dir[0]
		j := y + dir[1]
		if i >= 0 && j >= 0 && i < len(grid) && j < len(grid[0]) && grid[i][j] == '1' {
			dfs(grid, i, j)
		}
	}
}
