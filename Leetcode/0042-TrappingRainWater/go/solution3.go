func trap(height []int) int {
    n := len(height)
    lmax, rmax := 0, 0
    left, right := 0, n-1
    res := 0
    for left <= right {
        lmax = max(lmax, height[left])
        rmax = max(rmax, height[right])
        if lmax < rmax {
            res += lmax-height[left]
            left++
        } else {
            res += rmax-height[right]
            right--
        }
    }
    return res
}