package main

import (
    "fmt"
)

func spiralOrder(matrix [][]int) []int {
    var ret []int = []int{}
    if len(matrix) == 0 {
        return ret
    }
    minX, maxX := 0, len(matrix) - 1
    minY, maxY := 0, len(matrix[0]) - 1
    for minX <= maxX && minY <= maxY {
        for i := minY; i <= maxY; i++ {
            ret = append(ret, matrix[minX][i])
        }
        if minX++; minX > maxX {
            // 一旦无法向一个方向前进，就说明所有元素均以打印完毕
            break
        }
        for i := minX; i <= maxX; i++ {
            ret = append(ret, matrix[i][maxY])
        }
        if maxY--; minY > maxY {
            break
        }
        for i := maxY; i >= minY; i-- {
            ret = append(ret, matrix[maxX][i])
        }
        if maxX--; minX > maxX {
            break
        }
        for i := maxX; i >= minX; i-- {
            ret = append(ret, matrix[i][minY])
        }
        minY++
    }
    return ret
}

func main() {
    var matrix = [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
    //var matrix = [][]int{{2, 3}}
    fmt.Println("matrix:", matrix)
    ret := spiralOrder(matrix)
    fmt.Println("result:", ret)
}
