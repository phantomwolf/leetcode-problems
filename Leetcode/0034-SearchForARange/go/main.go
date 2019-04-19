package main

import (
	"fmt"
)

// Find the index of the leftmost or rightmost target inside nums
// left == true means we're searching for the leftmost target; otherwise, search for the rightmost one.
func extremeInsertionIndex(nums []int, target int, left bool) int {
    low, high := 0, len(nums)
    for low < high {
        mid := (low + high) / 2
        if target < nums[mid] || (target == nums[mid] && left == true) {
            high = mid
        } else {
            low = mid + 1
        }
    }
    if left && low < len(nums) && nums[low] == target {
        return low
    } else if !left && low - 1 < len(nums) && nums[low-1] == target {
        return low - 1
    }
    return -1
}

func searchRange(nums []int, target int) []int {
    res := []int{-1, -1}
    leftmost := extremeInsertionIndex(nums, target, true)
    if leftmost == -1 {
        return res
    }
    res[0] = leftmost
    rightmost := extremeInsertionIndex(nums, target, false)
    res[1] = rightmost
    return res
}

func main() {
    nums := []int{5,7,7,8,8,10}
    res := searchRange(nums, 100)
    fmt.Println(res)
}
