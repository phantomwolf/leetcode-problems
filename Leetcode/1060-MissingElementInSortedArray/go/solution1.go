package main

import "fmt"

func missingElement(nums []int, k int) int {
	if len(nums) == 1 {
		return nums[0] + k
	}
	for i := 1; i < len(nums); i++ {
		diff := nums[i] - nums[i-1] - 1
		if k-diff <= 0 {
			return nums[i-1] + k
		}
		k -= diff
	}
	return nums[len(nums)-1] + k
}

func main() {
	nums := []int{4, 7, 9, 10}
	k := 3
	res := missingElement(nums, k)
	fmt.Println(res)
}
