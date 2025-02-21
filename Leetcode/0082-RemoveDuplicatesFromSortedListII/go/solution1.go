package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	dummy := &ListNode{Val: -200, Next: head}
	// p0: previous unique node. p1: next unique node
	p0, p1 := dummy, head
	for p1 != nil {
		p2 := p1.Next
		// Proceed to next node if p1 is unique
		if p2 == nil || p1.Val != p2.Val {
			p0 = p1
			p1 = p2
			continue
		}
		// Remove duplicates
		val := p1.Val
		for p1 != nil && p1.Val == val {
			p2 = p1.Next
			p0.Next = p2
			p1 = p2
		}
		// p1 is either nil or a different value now
	}
	return dummy.Next
}
