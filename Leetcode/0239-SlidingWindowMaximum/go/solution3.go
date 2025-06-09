import "container/list"

func maxSlidingWindow(nums []int, k int) []int {
    var res []int
    deque := list.New()
    // Add first window to deque
    left, right := 0, 0
    for right < k {
        for deque.Len() > 0 && nums[deque.Back().Value.(int)] <= nums[right] {
            deque.Remove(deque.Back())
        }
        deque.PushBack(right)
        right++
    }
    res = append(res, nums[deque.Front().Value.(int)])
    // Move sliding window
    for right < len(nums) {
        left++
        for deque.Len() > 0 && deque.Front().Value.(int) < left {
            deque.Remove(deque.Front())
        }
        for deque.Len() > 0 && nums[deque.Back().Value.(int)] <= nums[right] {
            deque.Remove(deque.Back())
        }
        deque.PushBack(right)
        right++
        res = append(res, nums[deque.Front().Value.(int)])
    }
    return res
}