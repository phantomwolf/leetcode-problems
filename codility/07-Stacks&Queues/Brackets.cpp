#include <stack>

using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> stk;
    int length = S.size();
    for (int i = 0; i < length; ++i) {
        if (S[i] == ')') {
            if (stk.empty() || stk.top() != '(')
                return 0;
            stk.pop();
        } else if (S[i] == ']') {
            if (stk.empty() || stk.top() != '[')
                return 0;
            stk.pop();
        } else if (S[i] == '}') {
            if (stk.empty() || stk.top() != '{')
                return 0;
            stk.pop();
        } else {
            stk.push(S[i]);
        }
    }
    if (stk.empty())
        return 1;
    return 0;
}
