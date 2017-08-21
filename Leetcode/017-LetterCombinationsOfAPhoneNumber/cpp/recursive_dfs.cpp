#include <iostream>
#include <vector>
#include <string>

#define ATOI(c)     ((int)((c) - '0'))

const char *MAP[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string s("");
        traversal(res, digits, 0, std::move(s));
        return res;
    }

protected:
    void traversal(vector<string> &res, string &digits, int i, string &&s)
    {
        if (i == digits.size()) {
            res.push_back(s);
            return;
        }
        char digit = digits[i];
        for (int j = 0; MAP[ATOI(digit)][j] != '\0'; ++j) {
            traversal(res, digits, i + 1, s + MAP[ATOI(digit)][j]);
        }
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
