func sortedSquares(nums []int) []int {
    n := len(nums)
    res := make([]int, n)
    i, j := 0, n-1
    for k := n-1; k >= 0; k-- {
        if abs(nums[i]) < abs(nums[j]) {
            res[k] = nums[j] * nums[j]
            j--
        } else {
            res[k] = nums[i] * nums[i]
            i++
        }
    }
    return res
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}