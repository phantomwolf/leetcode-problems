#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        string::const_iterator iter = s.begin();
        while (iter != s.end()) {
            switch (*iter) {
            case '(':
            case '[':
            case '{':
                stk.push(*iter);
                break;
            case ')':
                if (stk.size() <= 0 || stk.top() != '(')   return false;
                stk.pop();
                break;
            case ']':
                if (stk.size() <= 0 || stk.top() != '[')   return false;
                stk.pop();
                break;
            case '}':
                if (stk.size() <= 0 || stk.top() != '{')   return false;
                stk.pop();
                break;
            }
            ++iter;
        }
        if (stk.size() != 0)
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    return 0;
}
