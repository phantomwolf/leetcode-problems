func sortColors(nums []int)  {
    n := len(nums)
    i, j, k := 0, 0, n-1
    for j <= k {
        if nums[j] == 0 {
            nums[i], nums[j] = nums[j], nums[i]
            j++
            i++
        } else if nums[j] == 2 {
            nums[j], nums[k] = nums[k], nums[j]
            k--
        } else {
            j++
        }
    }
}