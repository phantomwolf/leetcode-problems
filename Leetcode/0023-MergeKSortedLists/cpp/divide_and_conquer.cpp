#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge2Lists(ListNode *x, ListNode *y) {
        if (x == nullptr)
            return y;
        else if (y == nullptr)
            return x;

        ListNode *head;
        if (x->val < y->val) {
            head = x;
            x = x->next;
        } else {
            head = y;
            y = y->next;
        }
        ListNode *node = head;
        while (x != nullptr && y != nullptr) {
            if (x->val < y->val) {
                node->next = x;
                x = x->next;
            } else {
                node->next = y;
                y = y->next;
            }
            node = node->next;
        }
        if (x == nullptr)
            node->next = y;
        else
            node->next = x;
        return head;
    }

    ListNode *mergeKLists(vector<ListNode*> &lists) {
        unsigned int length = lists.size();
        if (length == 0)
            return nullptr;
        if (length == 1)
            return lists[0];
        while (length != 1) {
            int j = 0;
            for (int i = 0; i < length; i += 2) {
                if (i + 1 >= length) {
                    lists[j++] = lists[i];
                    break;
                }
                lists[j++] = this->merge2Lists(lists[i], lists[i + 1]);
            }
            length = j;
        }
        return lists[0];
    }
};
