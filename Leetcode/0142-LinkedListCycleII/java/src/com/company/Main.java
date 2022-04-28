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
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                break;
        }
        if (fast == null || fast.next == null) {
            // No circle
            return null;
        }
        // find the length of the circle
        int length = 0;
        do {
            fast = fast.next;
            length++;
        } while (fast != slow);
        // let fast go length steps
        fast = head;
        for (int i = 0; i < length; i++) {
            fast = fast.next;
        }
        // let fast and slow go in the same pace
        slow = head;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
}

public class Main {
    public static void main(String[] args) {
	// write your code here
    }
}
