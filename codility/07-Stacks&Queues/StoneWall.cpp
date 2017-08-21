#include <vector>
#include <stack>
#include <iostream>

using namespace std;


int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    int n = H.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    int count = 0;
    stack<int> stk;
    stk.push(H[0]);
    for (int i = 1; i < n; ++i) {
        while (stk.top() >= H[i]) {
            if (stk.top() > H[i])
                count++;
            stk.pop();
        }
        stk.push(H[i]);
    }
    count += stk.size();
    return count;
}
