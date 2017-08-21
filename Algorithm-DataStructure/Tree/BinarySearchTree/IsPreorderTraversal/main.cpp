#include <iostream>
#include <vector>
#include <stack>
#include <limits>


using namespace std;


bool is_preorder_traversal(const vector<int> &pre)
{
    stack<int> stk;
    int root = numeric_limits<int>::min();
    for (size_t i = 0; i < pre.size(); ++i) {
        if (pre[i] < root)
            return false;
        while (!stk.empty() && stk.top() < pre[i]) {
            root = stk.top();
            stk.pop();
        }
        stk.push(pre[i]);
    }
    return true;
}


int main(int argc, char *argv[])
{
    vector<int> pre1{40, 30, 35, 80, 100};
    vector<int> pre2{40, 30, 35, 20, 80, 100};

    cout << "pre1: " << is_preorder_traversal(pre1) << endl;
    cout << "pre2: " << is_preorder_traversal(pre2) << endl;


    return 0;
}
