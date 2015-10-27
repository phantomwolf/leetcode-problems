#include <iostream>
#include <vector>

using namespace std;


typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        if (k <= 1)
            return head;

        // placeholder root node
        ListNode root(0);
        root.next = head;

        ListNode *prev = &root, *node = head, *new_head;
        while ((new_head = reverseOneGroup(head, k)) != nullptr) {
            prev->next = new_head;
            prev = head;
            head = head->next;
        }

        return root.next;
    }

protected:
    ListNode *reverseOneGroup(ListNode *head, int k)
    {
        ListNode *new_head = head;
        for (int i = 1; i < k && new_head != nullptr; ++i) {
            new_head = new_head->next;
        }
        if (new_head == nullptr)
            return nullptr;

        ListNode *node = head, *prev = nullptr;
        while (prev != new_head) {
            ListNode *tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        head->next = node;
        return new_head;
    }
};


int main(int argc, char *argv[])
{
    vector<int> nums{1,2,3,4,5};
    ListNode head(nums[0]);
    ListNode *node = &head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *new_head = new ListNode(nums[i]);
        node->next = new_head;
        node = new_head;
    }

    Solution s;
    ListNode *new_head = s.reverseKGroup(&head, 2);
    for (node = new_head; node != nullptr; node = node->next) {
        cout << node->val << ", ";
    }
    cout << endl;

    return 0;
}
