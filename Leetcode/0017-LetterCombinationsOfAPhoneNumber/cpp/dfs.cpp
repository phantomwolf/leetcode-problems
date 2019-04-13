#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdint>

const char *MAP[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

using namespace std;

//深度优先搜索（迭代版）
class Solution
{
public:
    inline char digit2char(char digit, int i)
    {
        return MAP[digit - '0'][i];
    }

    string to_str(const string &digits, const deque<uint8_t> &stack)
    {
        string res;
        deque<uint8_t>::size_type length = stack.size();
        for (int i = 0; i < length; ++i) {
            res += digit2char(digits[i], stack[i]);
        }
        return res;
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> res;

        string::size_type length = digits.size();
        if (length == 0)
            return res;

        deque<uint8_t> stack;
        stack.push_back(0);
        while (!stack.empty()) {
            // advance as far as possible
            while (stack.size() != length) {
                stack.push_back(0);
            }
            // reached leaf node, add to result
            res.push_back(std::move(to_str(digits, stack)));
            // go back
            while (!stack.empty()) {
                uint8_t i = stack.back();
                stack.pop_back();
                ++i;
                if (digit2char(digits[stack.size()], i) != '\0') {
                    stack.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution s;

    string digits("23");
    vector<string> res = s.letterCombinations(digits);

    cout << '[';
    for (int i = 0; i < res.size(); ++i) {
        cout << '"' << res[i] << "\", ";
    }
    cout << ']' << endl;

    return 0;
}
