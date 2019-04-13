package main

import (
	"fmt"
)

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	return searchParallel(nums, 0, len(nums)-1, target)
}

func searchParallel(nums []int, l int, r int, target int) int {
	// This problem can be solved directly by
	// a modified version of binary search.
	for l <= r {
		m := (l + r) / 2
		if nums[m] == target {
			// Target found
			return m
		}
		if nums[l] < nums[m] && target > nums[m] {
			// Search rightward
			l = m + 1
			continue
		} else if nums[l] > nums[m] && target < nums[m] {
			// Search leftward
			r = m - 1
			continue
		}
		// Otherwise, search both sides in different goroutines
        // NOTE: This function creats too many goroutines, which 
        // makes it slower than an ordinary recursive approach
		ch := make(chan int)
		// Search leftward
		go func() {
			ret := searchParallel(nums, l, m-1, target)
			ch <- ret
		}()
		// Search rightward
		go func() {
			ret := searchParallel(nums, m+1, r, target)
			ch <- ret
		}()
		for i := 0; i < 2; i++ {
			ret := <-ch
			if ret != -1 {
				return ret
			}
		}
		return -1
	}
	return -1
}

func main() {
	var nums = []int{1, 3}
	var targets = []int{0}
	for _, e := range targets {
		index := search(nums, e)
		fmt.Println(index)
	}

}
