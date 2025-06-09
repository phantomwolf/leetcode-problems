type Pair struct {
    Val int
    Index int
}

type MaxHeap []Pair

func (h MaxHeap) Len() int {
    return len(h)
}

func (h MaxHeap) Less(i, j int) bool {
    return h[i].Val > h[j].Val
}

func (h MaxHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *MaxHeap) Push(x any) {
    *h = append(*h, x.(Pair))
}

func (h *MaxHeap) Pop() any {
    n := len(*h)
    item := (*h)[n-1]
    *h = (*h)[0:n-1]
    return item
}

func maxSlidingWindow(nums []int, k int) []int {
    result := []int{}
    pq := &MaxHeap{}
    heap.Init(pq)
    left, right := 0, 0
    for right < len(nums) {
        // Expand window
        heap.Push(pq, Pair{
            Val: nums[right],
            Index: right,
        })
        right++
        if right-left == k {
            for (*pq)[0].Index < left {
                heap.Pop(pq)
            }
            result = append(result, (*pq)[0].Val)
            // Shrink window
            left++
        }
    }
    return result
}