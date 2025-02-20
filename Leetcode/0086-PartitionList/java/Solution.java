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
public class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }
        ListNode less = new ListNode(0, head);
        ListNode more = new ListNode();
        // Remove nodes which are greater than or equal to x and add them to new list
        ListNode p1 = head;
        ListNode p4 = more;
        ListNode p0 = less;
        while (p1 != null) {
            ListNode p2 = p1.next;
            if (p1.val >= x) {
                // Remove p1 from less list
                p0.next = p2;
                p1.next = null;
                // Add p1 to more list and proceed
                p4.next = p1;
                p4 = p4.next;
                // Proceed p1 to next position
                p1 = p2;
            } else {
                p0 = p1;
                p1 = p2;
            }
        }
        // Connect less and more lists
        p0.next = more.next;
        return less.next;
    }
}
