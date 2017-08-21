package main

import (
	"fmt"
)

func generateMatrix(n int) [][]int {
	// generate matrix
	var matrix = make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	// fill in the matrix in spiral order
	num := 1
	minX, maxX, minY, maxY := 0, n-1, 0, n-1
	for num != n*n+1 {
		for y := minY; y <= maxY; y++ {
            matrix[minX][y] = num
            num++
		}
        minX++
        for x := minX; x <= maxX; x++ {
            matrix[x][maxY] = num
            num++
        }
        maxY--
        for y := maxY; y >= minY; y-- {
            matrix[maxX][y] = num
            num++
        }
        maxX--
        for x := maxX; x >= minX; x-- {
            matrix[x][minY] = num
            num++
        }
        minY++
	}
    return matrix
}

func main() {
    matrix := generateMatrix(5)
    // Print matrix
    fmt.Println("matrix:")
    for j := 0; j < len(matrix[0]); j++ {
        for i := 0; i < len(matrix); i++ {
            fmt.Printf("%4d", matrix[i][j])
        }
        fmt.Printf("\n")
    }
}
