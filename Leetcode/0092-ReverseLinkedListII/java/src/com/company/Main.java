package com.company;

/**
 * Definition for singly-linked list.
 */
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0, head);

        ListNode part1Tail = dummy;
        for (int i = 0; i < left - 1; i++) {
            part1Tail = part1Tail.next;
        }
        ListNode part2Tail = part1Tail.next;

        ListNode prev = null, node = part1Tail.next;
        for (int i = left; i <= right; i++) {
            ListNode tmp = node.next;
            node.next = prev;
            prev = node;
            node = tmp;
        }

        ListNode part2Head = prev;
        ListNode part3Head = node;
        part1Tail.next = part2Head;
        part2Tail.next = part3Head;
        return dummy.next;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
