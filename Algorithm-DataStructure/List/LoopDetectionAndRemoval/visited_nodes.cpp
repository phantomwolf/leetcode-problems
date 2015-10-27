#include <ctime>
#include <cstdlib>
#include <iostream>
#include <unordered_set>

using namespace std;


typedef struct ListNode ListNode;

struct ListNode {
    int data;
    ListNode *next;
};

ListNode *build_list_with_loop()
{
    ListNode *head = new ListNode;
    head->data = rand() % 100;

    ListNode *node = head;
    ListNode *loop_start = nullptr;
    for (int i = 0; i < 9; ++i) {
        node->next = new ListNode;
        node = node->next;
        node->data = rand() % 100;
        if (i == 5)
            loop_start = node;
    }
    node->next = loop_start;
    return head;
}

void print_list(ListNode *head, int max_nodes)
{
    for (int i = 0; i < max_nodes && head != nullptr; ++i) {
        cout << head->data << ", ";
        head = head->next;
    }
    cout << endl;
}

void detect_loop(ListNode *head)
{
    unordered_set<ListNode *> set;
    ListNode *node = head;
    while (node != nullptr && set.find(node) == set.end()) {
        set.insert(node);
        node = node->next;
    }
    if (node == nullptr) {
        cout << "No loop detected" << endl;
        return;
    }
    cout << "Loop detected at " << node->data << endl;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    ListNode *head = build_list_with_loop();
    print_list(head, 20);
    detect_loop(head);

    return 0;
}
