# 142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:

* The number of the nodes in the list is in the range [0, 104].
* -105 <= Node.val <= 105
* pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?

## Solution: fast and slow pointers
This problem doesn't need the dummy head node.

To detect cycle, let `fast` move 2 steps each time, and `slow` move 1 step each time. If `fast` and `slow` meets, there's a cycle in the linked list.

To calculate the length of the cycle, let `fast` move until it meets `slow` again. Use a int to record the length.

To find the node where the cycle begins, let slow restart from the list head `slow = head`, and let `slow` and `fast` move at the same pace. The meeting point is where the cycle begins.

[Detailed explanation](../../Algorithm/List/CycleDetectionAndRemoval/README.rst)
