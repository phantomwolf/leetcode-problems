/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        // Let fast move forward n steps
        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }
        // Let fast and slow move forward at the same pace
        ListNode prev = null;
        while (fast != null) {
            prev = slow;
            fast = fast.next;
            slow = slow.next;
        }
        // prev is the previous node of slow
        prev.next = slow.next;
        return dummy.next;
    }
}