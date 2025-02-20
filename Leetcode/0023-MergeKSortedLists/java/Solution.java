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
class Pair {
    public int val;
    public ListNode node;

    public Pair(int val, ListNode node) {
        this.val = val;
        this.node = node;
    }
}

public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode();
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            return a.val - b.val;
        });
        // Add the first node of each list into priority queue
        for (ListNode p : lists) {
            if (p != null) {
                pq.add(new Pair(p.val, p));
            }
        }
        ListNode p = dummy;
        while (!pq.isEmpty()) {
            Pair pair = pq.remove();
            // Add this node to result
            p.next = pair.node;
            p = p.next;
            // Add next node into priority queue
            ListNode next = pair.node.next;
            if (next != null) {
                pq.add(new Pair(next.val, next));
            }
        }
        return dummy.next;
    }
}