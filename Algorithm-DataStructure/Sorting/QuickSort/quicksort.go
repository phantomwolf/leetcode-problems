package main

import (
	"fmt"
	"math/rand"
)

func quick_sort(nums []int) {
        var length = len(nums)
        var p = rand.Intn(length)
        // swap p to the beginning
        nums[0], nums[p] = nums[p], nums[0]

        var l = 1
        var r = length - 1
        for true {
            for l < length && nums[l] < nums[0] {
                l++
            }
            for r > 0 && nums[r] > nums[0] {
                r--
            }
            if l >= r {
                nums[0], nums[r] = nums[r], nums[0]
                break
            }
            nums[l], nums[r] = nums[r], nums[l]
            l++
            r--
        }
        if r > 1 {
            quick_sort(nums[:r])
        }
        if r <  length - 2 {
            quick_sort(nums[r + 1:])
        }
}

func main() {
	nums := []int{3, 7, 5, 1, 2, 4, 8, 7, 3}
	fmt.Println(nums)
        quick_sort(nums)
	fmt.Println(nums)
}
