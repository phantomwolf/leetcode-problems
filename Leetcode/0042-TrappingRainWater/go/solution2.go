func trap(height []int) int {
    n := len(height)
    // leftMax[i]: max height in range [0, i]
    leftMax := make([]int, n)
    leftMax[0] = height[0]
    // rightMax[i]: max height in range [i, n)
    rightMax := make([]int, n)
    rightMax[n-1] = height[n-1]
    for i := 1; i < n; i++ {
        j := n-i-1
        leftMax[i] = max(leftMax[i-1], height[i])
        rightMax[j] = max(rightMax[j+1], height[j])
    }

    res := 0
    for i := 1; i < n-1; i++ {
        rain := min(leftMax[i], rightMax[i])-height[i]
        res += rain
    }
    return res
}