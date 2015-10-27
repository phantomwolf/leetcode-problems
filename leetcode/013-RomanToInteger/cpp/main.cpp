#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
/*
    I: 1
    V: 5
    X: 10
    L: 50
    C: 100
    D: 500
    M: 1000
*/
    static const unsigned int DIGITS_LENGTH = 8;
    static char DIGITS[DIGITS_LENGTH];

    static int digitToInt(char digit);
    static int indexOfDigit(char digit);

    int romanToInt(string s);
};

char Solution::DIGITS[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'};

int Solution::indexOfDigit(char digit)
{
    for (unsigned int i=0; i < Solution::DIGITS_LENGTH; ++i) {
        if (Solution::DIGITS[i] == digit)
            return i;
    }
    return -1;
}

int Solution::digitToInt(char digit)
{
    switch (digit) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int Solution::romanToInt(string s)
{
    int ret = 0;
    string::const_iterator iter = s.begin();
    char prev = '\0';
    while (iter != s.end()) {
        if (this->indexOfDigit(*iter) <= this->indexOfDigit(prev)) {
            ret += Solution::digitToInt(prev);
            prev = *iter;
            ++iter;
            continue;
        }
        ret += Solution::digitToInt(*iter) - Solution::digitToInt(prev);
        prev = '\0';
        ++iter;
    }
    ret += Solution::digitToInt(prev);
    return ret;
}

int main()
{
    Solution s;
    string num = "VI";
    cout << s.romanToInt(num) << endl;
    return 0;
}

