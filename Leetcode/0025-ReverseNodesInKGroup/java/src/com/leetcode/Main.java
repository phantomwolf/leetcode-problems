package com.leetcode;

class RecursiveSolution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode end = head;
        for (int i = 0; i < k; i++) {
            if (end == null) {
                // Less than k nodes. No need to reverse
                return head;
            }
            end = end.next;
        }
        ListNode newHead = reverseRange(head, end);
        head.next = reverseKGroup(end, k);
        return newHead;
    }

    // Reverse nodes with [start, end)
    private ListNode reverseRange(ListNode start, ListNode end) {
        ListNode prev = null, curr = start;
        while (curr != end) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}

class InterativeSolution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode prevGroupTail = dummy, start = head;
        ListNode nextGroupHead;
        while (true) {
            nextGroupHead = start;
            for (int i = 0; i < k; i++) {
                if (nextGroupHead == null) {
                    // Less than k nodes. Done
                    prevGroupTail.next = start;
                    return dummy.next;
                }
                nextGroupHead = nextGroupHead.next;
            }
            // reverse [start, nextGroupHead)
            prevGroupTail.next = reverseRange(start, nextGroupHead);
            // update variables
            prevGroupTail = start;
            start = nextGroupHead;
        }
    }

    // Reverse [start, end). Returns the new head node after reversing
    private ListNode reverseRange(ListNode start, ListNode end) {
        ListNode prev = null, curr = start;
        while (curr != end) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
