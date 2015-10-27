/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        struct ListNode root(0);
        root.next = head;

        ListNode *prev = &root;
        ListNode *first = root.next;
        ListNode *second = (first == nullptr) ? nullptr : first->next;

        while (first != nullptr && second != nullptr) {
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            first = prev->next;
            if (first != nullptr)
                second = first->next;
        }

        return root.next;
    }
};
