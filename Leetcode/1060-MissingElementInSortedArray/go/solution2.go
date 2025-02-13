package main

import "fmt"

func missingElement(nums []int, k int) int {
	if len(nums) == 1 {
		return nums[0] + k
	}
	// Binary search
	// Target: find an i, so that countMissingElements(i) < k and countMissingElements(i+1) >= k
	left, right := 0, len(nums)
	for left < right {
		mid := left + (right-left)/2
		if countMissingElements(nums, mid) < k {
			left = mid + 1
		} else if countMissingElements(nums, mid) > k {
			right = mid
		} else {
			right = mid
		}
	}
	// left - 1 is the target
	return k - countMissingElements(nums, left-1) + nums[left-1]
}

func countMissingElements(nums []int, i int) int {
	totalElements := nums[i] - nums[0] + 1
	presentElements := i - 0 + 1
	return totalElements - presentElements
}

func main() {
	nums := []int{4, 7, 9, 10}
	k := 3
	res := missingElement(nums, k)
	fmt.Println(res)
}
