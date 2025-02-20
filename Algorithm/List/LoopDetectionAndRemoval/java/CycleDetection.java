public class CycleDetection {
    // Detect cycle and return the starting node of it
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode fast = head, slow = head;
        while (fast != null) {
            fast = fast.next;
            if (fast != null) {
                fast = fast.next;
            }
            slow = slow.next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == null) {
            // No cycle
            return null;
        }
        // Let slow start from the beginning again and both pointers move at the same
        // pace
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        // slow and fast will meet at the starting point of the cycle
        return slow;
    }
}
