#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 ||
            (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (divisor == 1)
            return dividend;

        int res = -1;
        bool sign = ((dividend < 0) ^ (divisor < 0)) ? false : true;
        if (dividend > 0)
            dividend = -dividend;
        if (divisor < 0)
            divisor = -divisor;
        while (dividend <= 0) {
            dividend += divisor;
            ++res;
        }
        return (sign == true) ? res : -res;
    }
};


int main(int argc, char *argv[])
{
    int a = -2147483648;
    int b = 2;

    Solution s;
    int res = s.divide(a, b);
    cout << a << " / " << b << " = " << res << endl;

    return 0;
}
