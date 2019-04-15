package main

import (
	"fmt"
)

func selfDividingNumbers(left int, right int) []int {
	var res []int
	for i := left; i <= right; i++ {
		if isSelfDividing(i) {
			res = append(res, i)
		}
	}
	return res
}

func isSelfDividing(num int) bool {
	tmp := num
	for tmp != 0 {
		digit := tmp % 10
		if digit == 0 || num%digit != 0 {
			return false
		}
		tmp /= 10
	}
	return true
}

func main() {
	res := selfDividingNumbers(1, 22)
	fmt.Println(res)
}
