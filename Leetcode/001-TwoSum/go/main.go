package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	var m = map[int]int{}
	for i, e := range nums {
		v, ok := m[target-e]
		if ok {
			return []int{v, i}
		}
		m[e] = i
	}
	return []int{}
}

func main() {
	var nums = []int{2, 7, 11, 15}
	var target = 9
	ret := twoSum(nums, target)
	fmt.Println("Result:", ret)
}
