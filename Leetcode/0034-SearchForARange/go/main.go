package main

import (
	"fmt"
)

// Find the leftmost or one position past rightmost target in [low, high] of nums
func extremeInsertionIndex(nums []int, target int, low int, high int, left bool) int {
    for low < high {
        mid := (low + high) / 2
        if nums[mid] > target || (left && target == nums[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low
}

func searchRange(nums []int, target int) []int {
    var ret []int = []int{-1, -1}
    // First, use binary search to find one target
    low, high := 0, len(nums) - 1
    index := -1
    for low <= high {
        mid := (low + high) / 2
        if nums[mid] == target {
            index = mid
            break
        }
        if nums[mid] < target {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }
    // No target found
    if index == -1 {
        return ret
    }
    // Find leftmost target
    ret[0] = extremeInsertionIndex(nums, target, low, index, true)
    if nums[ret[0]] != target {
        ret[0] = -1
    }
    ret[1] = extremeInsertionIndex(nums, target, index, high, false) - 1
    if nums[ret[1]] != target {
        ret[1] = -1
    }
    return ret
}

func main() {
    var nums []int = []int{5, 7, 7, 8, 8, 10}
    var target int = 8
    ret := searchRange(nums, target)
    fmt.Println(ret)
}
