package ReverseNodesInEvenLengthGroups;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/*
 * Count the length of each group, and reverse the even ones
 */
public class Solution1 {
    public ListNode reverseEvenLengthGroups(ListNode head) {
        int maxLen = 1;
        ListNode dummy = new ListNode(0, head);
        ListNode before = dummy;
        while (before != null) {
            before = reverseGroup(before, maxLen);
            maxLen++;
        }
        return dummy.next;
    }

    private ListNode reverseGroup(ListNode before, int maxLen) {
        if (before.next == null) {
            return null;
        }
        ListNode node = before.next, prev = null;
        int len = 0;
        while (len < maxLen && node != null) {
            prev = node;
            node = node.next;
            len++;
        }
        if (len % 2 != 0) {
            return prev;
        }
        // Reverse
        ListNode after = node;
        node = before.next;
        ListNode newTail = node;
        prev = null;
        while (node != after) {
            ListNode next = node.next;
            node.next = prev;
            prev = node;
            node = next;
        }
        // Re-connect groups
        before.next = prev;
        newTail.next = after;
        return newTail;
    }}
