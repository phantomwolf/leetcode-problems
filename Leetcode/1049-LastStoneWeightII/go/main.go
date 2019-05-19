package main

import (
    "fmt"
)


func lastStoneWeightII(stones []int) int {
    largest := 0
    totalWeight := 0
    for _, w := range stones {
        totalWeight += w
    }
    halfWeight := totalWeight / 2

    d := make([][]bool, halfWeight + 1)
    for i := range d {
        d[i] = make([]bool, len(stones))
    }

    for i := 0; i < len(stones); i++ {
        d[0][i] = true
    }
    d[stones[0]][0] = true
    for w := 1; w <= halfWeight; w++ {
        for i := 1; i < len(stones); i++ {
            d[w][i] = d[w][i-1]
            if w >= stones[i] {
                d[w][i] = d[w][i] || d[w-stones[i]][i-1]
            }
            if d[w][i] == true {
                largest = w
            }
        }
    }
    return totalWeight - largest * 2
}

func main() {
    //stones := []int{2,7,4,1,8,1}
    stones := []int{1,3,4,3,5,4}
    res := lastStoneWeightII(stones)
    fmt.Println(res)
}
