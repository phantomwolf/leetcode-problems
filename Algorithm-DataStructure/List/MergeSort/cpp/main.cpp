/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *sortList(ListNode* head)
    {
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            ++length;
            node = node->next;
        }
        return this->mergeSort(head, length);
    }

protected:
    ListNode *mergeSort(ListNode *head, int length)
    {
        if (head == nullptr || length <= 1)
            return head;
        // Divide list to 2 halves and sort
        int half = length / 2;
        ListNode *node = head;
        for (int i = 1; i < half; ++i) {
            node = node->next;
        }

        ListNode *a = head;
        ListNode *b = node->next;
        node->next = nullptr;
        a = this->mergeSort(a, half);
        b = this->mergeSort(b, length - half);
        return this->merge(a, b);
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *head = nullptr;
        if (a->val <= b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }

        ListNode *node = head;
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                node->next = a;
                a = a->next;
            } else {
                node->next = b;
                b = b->next;
            }
            node = node->next;
        }
        if (a == nullptr)
            node->next = b;
        else
            node->next = a;
        return head;
    }
};
