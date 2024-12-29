#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    struct Node *next;
};

void print_list(Node *head, int max_nodes)
{
    for (int i = 0; i < max_nodes && head != NULL; ++i) {
        printf("%d(%lx), ", head->data, (unsigned long)head);
        head = head->next;
    }
    puts("");
}

Node *build_list_with_loop()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;

    Node *node = head;
    Node *loop_start = NULL;
    for (int i = 0; i < 9; ++i) {
        node->next = (Node *)malloc(sizeof(Node));
        node = node->next;
        node->data = i + 2;
        if (i == 5)
            loop_start = node;
    }
    node->next = loop_start;
    return head;
}

void floyd_detect_remove_loop1(Node *list)
{
    Node *slow = list, *fast = list;
    do {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    } while (fast != NULL && fast != slow);

    if (fast == NULL) {
        puts("No loop detected");
        return;
    }
    // Calculate loop length and find last node in the loop
    size_t length = 1;
    while (slow->next != fast) {
        slow = slow->next;
        length++;
    }
    printf("Loop length: %lu\n", length);
    // Find loop start node
    slow = fast = list;
    Node *loop_end;
    for (size_t i = 0; i < length; i++) {
        fast = fast->next;
    }
    while (slow != fast) {
        slow = slow->next;
        loop_end = fast;
        fast = fast->next;
    }
    printf("Loop start point: %d\n", slow->data);
    printf("Loop end point: %d\n", loop_end->data);
    // Remove loop
    loop_end->next = NULL;
}

void floyd_detect_remove_loop2(Node *list)
{
    Node *slow = list, *fast = list;
    do {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    } while (fast != NULL && fast != slow);

    if (fast == NULL) {
        puts("No loop detected");
        return;
    }
    // Find loop start point
    slow = list;
    Node *loop_end;
    while (slow != fast) {
        slow = slow->next;
        loop_end = fast;
        fast = fast->next;
    }
    printf("Loop start point: %d\n", slow->data);
    printf("Loop end point: %d\n", loop_end->data);
    // Remove loop
    loop_end->next = NULL;
}


int main(int argc, char *argv[])
{
    Node *head = build_list_with_loop();
    print_list(head, 20);
    floyd_detect_remove_loop2(head);
    print_list(head, 20);

    return 0;
}
