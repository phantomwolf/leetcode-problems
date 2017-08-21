package main

import (
	"fmt"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	// Return immediately if one list is empty
	if l1 == nil {
		return l2
	} else if l2 == nil {
		return l1
	}
	// dummy root node
	root := new(ListNode)
	carry := 0
	for lst := root; l1 != nil || l2 != nil || carry != 0; lst = lst.Next {
		val1, val2 := 0, 0
		if l1 != nil {
			val1 = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val2 = l2.Val
			l2 = l2.Next
		}
		val := val1 + val2 + carry
		if val >= 10 {
			val -= 10
			carry = 1
		} else {
			carry = 0
		}
		lst.Next = &ListNode{val, nil}
	}
	return root.Next
}

func main() {
}
