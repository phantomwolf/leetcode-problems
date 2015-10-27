/* Depth-first traversal of Binary Search Tree(BST) */
#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

#include <glib.h>

void preorder_traversal_non_recursive(Tree *tree)
{
    printf("Preorder traversal: ");
    /* Use double-ended queue as stack */
    GQueue *stack = g_queue_new();

    Node *node = tree->root;
    while (!g_queue_is_empty(stack) || node != NULL) {
        while (node != NULL) {
            printf("%d, ", node->data);
            g_queue_push_tail(stack, node);
            node = node->left;
        }
        if (!g_queue_is_empty(stack)) {
            node = g_queue_pop_tail(stack);
            node = node->right;
        }
    }
    puts("");

    g_queue_free(stack);
}

void inorder_traversal_non_recursive(Tree *tree)
{
    printf("Inorder traversal: ");
    /* Use double-ended queue as stack */
    GQueue *stack = g_queue_new();

    Node *node = tree->root;
    while (!g_queue_is_empty(stack) || node != NULL) {
        while (node != NULL) {
            g_queue_push_tail(stack, node);
            node = node->left;
        }
        if (!g_queue_is_empty(stack)) {
            node = g_queue_pop_tail(stack);
            printf("%d, ", node->data);
            node = node->right;
        }
    }
    puts("");

    g_queue_free(stack);
}


void postOrder2(BinTree *root)    //非递归后序遍历
{
    stack<BTNode*> s;
    BinTree *p=root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
        {
            BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出现在栈顶 
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;    
            }
            else                        //第二次出现在栈顶 
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }    
}

void postOrder3(BinTree *root)     //非递归后序遍历
{
    stack<BinTree*> s;
    BinTree *cur;                      //当前结点 
    BinTree *pre=NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
              s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
}


int main(int argc, char *argv[])
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree_init(tree);

    // Insert data
    //                      20
    //                    /    \
    //                  15      25
    //                /   \      \
    //               10   18      30
    //                \
    //                 12
    //
    tree_insert(tree, 20);
    tree_insert(tree, 15);
    tree_insert(tree, 18);
    tree_insert(tree, 10);
    tree_insert(tree, 12);

    tree_insert(tree, 25);
    tree_insert(tree, 30);

    print_tree(tree->root);
    puts("");

    preorder_traversal_non_recursive(tree);
    inorder_traversal_non_recursive(tree);


    return 0;
}
