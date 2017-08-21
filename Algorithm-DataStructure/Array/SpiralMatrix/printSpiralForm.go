package main

import (
    "fmt"
)


func printSpiralForm(matrix [][]int) {
    minX, maxX := 0, len(matrix) - 1
    minY, maxY := 0, len(matrix[0]) - 1
    for minX <= maxX && minY <= maxY {
        for i := minX; i <= maxX; i++ {
            fmt.Printf("%d, ", matrix[i][minY])
        }
        // Now all elements with an y index of minY have been printed. Increase minY
        minY++
        for i := minY; i <= maxY; i++ {
            fmt.Printf("%d, ", matrix[maxX][i])
        }
        // Now all elements with an x index of maxX have been printed. Decrease maxX
        maxX--
        for i := maxX; i >= minX; i-- {
            fmt.Printf("%d, ", matrix[i][maxY])
        }
        // Now all elements with an y index of maxY have been printed. Decrease maxY
        maxY--
        for i := maxY; i >= minY; i-- {
            fmt.Printf("%d, ", matrix[minX][i])
        }
        // Now all elements with an x index of minX have been printed. Increase minX
        minX++
    }
    fmt.Printf("\n")
}


func main() {
    var matrix = [][]int{{1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16}}
    printSpiralForm(matrix)
}
