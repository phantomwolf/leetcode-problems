# 19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

![example1](remove_ex1.jpg)

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:

* The number of nodes in the list is sz.
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz

Follow up: Could you do this in one pass?

## Solution: one pass
Since this is a singly-linked list, there's no way to go backward, so we can't reach the end and go back without modifying the linked list.

However, we can use this trick: use 2 pointers fast and slow. First, let fast move forward n steps. Then let fast and slow move forward at the same pace, so that when fast reaches the end, slow will be at the nth node from the end of the list. This way we don't have to modify the linked list and can solve the problem in one pass.