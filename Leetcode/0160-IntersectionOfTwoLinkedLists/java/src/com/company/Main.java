package com.company;

/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; next = null; }
}

class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // Connect list B to the end of list A
        // If there's a circle in this new list, then A and B intersects and the beginning of the intersection is the beginning of the circle
        ListNode node = headA;
        while (node.next != null) {
            node = node.next;
        }
        // Connect B to the end of A
        ListNode tailA = node;
        node.next = headB;
        // Detect circle
        ListNode slow = tailA, fast = tailA;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
        }
        do {
            fast = fast.next;
            if (fast != null) {
                fast = fast.next;
            }
            slow = slow.next;
        } while (fast != null && fast != slow);
        if (fast == null) {
            // No circle. A and B don't intersect
            // Detach A and B
            tailA.next = null;
            return null;
        }
        // Figure out the length of the circle
        int length = 0;
        do {
            fast = fast.next;
            length++;
        } while (fast != slow);
        // Find the beginning node of the circle
        fast = headA;
        for (int i = 0; i < length; i++) {
            fast = fast.next;
        }
        slow = headA;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        // Detach A and B
        tailA.next = null;
        return slow;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
