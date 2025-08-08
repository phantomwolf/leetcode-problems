package main

import "math"

func merge(nums1 []int, m int, nums2 []int, n int) {
	// j is index for nums1, k is index for nums2
	j, k := m-1, n-1
	for i := m + n - 1; i >= 0; i-- {
		v1, v2 := math.MinInt, math.MinInt
		if j >= 0 {
			v1 = nums1[j]
		}
		if k >= 0 {
			v2 = nums2[k]
		}
		if v1 > v2 {
			nums1[i] = v1
			j--
		} else {
			nums1[i] = v2
			k--
		}
	}
}
