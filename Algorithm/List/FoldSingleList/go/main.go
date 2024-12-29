package main

import (
	"fmt"
)

type Node struct {
	Val  int
	Next *Node
}

// Convert a slice to single linked list
func SliceToList(s []int) *Node {
    if len(s) == 0 {
        return nil
    }

    h := &Node{Val: s[0], Next: nil}
    n := h
    for i := 1; i < len(s); i++ {
        n.Next = &Node{Val: s[i], Next: nil}
        n = n.Next
    }

    return h
}

func PrintList(head *Node) {
    if head == nil {
        return
    }
    fmt.Printf("%d", head.Val)

    node := head.Next
    for node != nil {
        fmt.Printf(" -> %d", node.Val)
        node = node.Next
    }
    fmt.Print("\n")
}

func FoldList(head *Node) {
    // Use fast & slow pointers to locate the middle of the list
    fast, slow := head, head
    for fast.Next != nil {
        fast = fast.Next
        if fast.Next != nil {
            fast = fast.Next
            slow = slow.Next
        }
    }
    mid := slow.Next
    slow.Next = nil

    // Reverse the right half
    prev := (*Node)(nil)
    for curr, next := mid, mid.Next; curr != nil; prev, curr = curr, next {
        next = curr.Next
        curr.Next = prev
    }
    head2 := prev

    // Merge two linked lists
    for node := head; head2 != nil; {
        next2 := head2.Next
        head2.Next = node.Next
        node.Next = head2

        node = head2.Next
        head2 = next2
    }
}


func main() {
    s1 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
    h1 := SliceToList(s1)
    fmt.Print("Before: ")
    PrintList(h1)
    FoldList(h1)
    fmt.Print("After:  ")
    PrintList(h1)

    s2 := []int{1, 2, 3, 4, 5, 6}
    h2 := SliceToList(s2)
    fmt.Print("Before: ")
    PrintList(h2)
    FoldList(h2)
    fmt.Print("After:  ")
    PrintList(h2)
}
