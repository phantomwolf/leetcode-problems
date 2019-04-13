#include <iostream>
#include <string>


#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool positive = true;

        string::iterator iter = str.begin();
        // skip whitespace characters
        while (*iter == 32)
            ++iter;
        // optional plus/minus sign
        if (*iter == '+') {
            ++iter;
        } else if (*iter == '-') {
            positive = false;
            ++iter;
        }
        // digits
        while (*iter > 47 && *iter < 58) {
            int digit = positive ? (*iter - 48) : (48 - *iter);
            if (positive) {
                if (res > INT_MAX/10)
                    return INT_MAX;
                res *= 10;
                if (res > INT_MAX - digit)
                    return INT_MAX;
                res += digit;
            } else {
                if (res < INT_MIN/10)
                    return INT_MIN;
                res *= 10;
                if (res < INT_MIN - digit)
                    return INT_MIN;
                res += digit;
            }
            ++iter;

        }
        return res;
    }
};

int main()
{
    string s("    +00134");
    Solution sl;
    cout << sl.myAtoi(s) << endl;
    return 0;
}

