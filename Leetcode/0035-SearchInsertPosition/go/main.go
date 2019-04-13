package main

import (
    "fmt"
)

// Find a number which is just greater than target, return its index
func searchInsert(nums []int, target int) int {
    // Empty nums
    if len(nums) == 0 {
        return 0
    }

    l, r := 0, len(nums) - 1

    // If last element is smaller than target
    if nums[r] < target {
        return r + 1
    }

    for l < r {
        m := (l + r) / 2
        if nums[m] == target {
            return m
        } else if nums[m] > target {
            // m is not excluded
            r = m
        } else {
            l = m + 1
        }
    }
    return r
}

func main() {
    nums := []int{}
    target := 0
    result := searchInsert(nums, target)
    fmt.Println("Result:", result)
}
