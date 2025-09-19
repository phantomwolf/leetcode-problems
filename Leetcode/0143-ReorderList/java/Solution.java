/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        // Find the middle of the list
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        // slow stops at the tail of the 1st half
        // Split the list
        ListNode tmp = slow;
        slow = slow.next;
        tmp.next = null;

        // Reverse the 2nd half
        ListNode prev = null;
        while (slow != null) {
            tmp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = tmp;
        }

        // Merge 2 lists
        ListNode dummy = new ListNode();
        ListNode node = dummy;
        ListNode node1 = head;
        ListNode node2 = prev;
        while (node2 != null) {
            node.next = node1;
            node1 = node1.next;
            node = node.next;

            node.next = node2;
            node2 = node2.next;
            node = node.next;
        }
        // If odd number of nodes, handle the last node
        if (node1 != null) {
            node.next = node1;
        }
    }
}