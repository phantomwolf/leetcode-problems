#include <stack>

using std::stack;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int length = A.size();
    int eaten  = 0;
    stack<int> stk;         // only store fish flowing downstream
    for (int i = 0; i < length; ++i) {
        if (B[i] == 1) {
            stk.push(A[i]);
            continue;
        }
        while (!stk.empty() && stk.top() < A[i]) {
            stk.pop();
            eaten++;
        }
        if (!stk.empty())
            eaten++;        // Fish A[i] got eaten
    }
    return length - eaten;
}
