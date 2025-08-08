/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
import "container/heap"

type MinHeap []*ListNode

func (h MinHeap) Len() int { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h MinHeap) Swap(i, j int) {h[i], h[j] = h[j], h[i]}

func (h *MinHeap) Push(x any) {
    node := x.(*ListNode)
    (*h) = append(*h, node)
}

func (h *MinHeap) Pop() any {
    val := (*h)[len(*h)-1]
    (*h) = (*h)[:len(*h)-1]
    return val
}

func mergeKLists(lists []*ListNode) *ListNode {
    dummy := &ListNode{}
    // Add initial K elements into min heap
    h := &MinHeap{}
    heap.Init(h)
    for _, node := range lists {
        if node != nil {
            heap.Push(h, node)
        }
    }
    node := dummy
    for h.Len() > 0 {
        node.Next = heap.Pop(h).(*ListNode)
        node = node.Next
        if node.Next != nil {
            heap.Push(h, node.Next)
        }
    }
    return dummy.Next
}