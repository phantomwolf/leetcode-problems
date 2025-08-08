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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> {
            return a.val - b.val;
        });
        ListNode dummy = new ListNode();
        // Add initial k nodes into pq
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }
        ListNode node = dummy;
        while (!pq.isEmpty()) {
            node.next = pq.remove();
            node = node.next;
            if (node.next != null) {
                pq.add(node.next);
            }
        }
        return dummy.next;
    }
}