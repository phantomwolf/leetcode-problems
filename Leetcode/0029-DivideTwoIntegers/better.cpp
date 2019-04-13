#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 若被除数为0，或被除数为-2147483648且除数为-1，
        // 会产生溢出，按题目规定返回INT_MAX。
        if (divisor == 0 ||
            (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        // 若被除数为-2147483648，除非除数也为-2147483648，
        // 否则结果必为0。
        // 这样就处理了被除数为INT_MIN的情况，保证之后abs(divisor)不会溢出
        if (divisor == INT_MIN)
            return (dividend == INT_MIN) ? 1 : 0;

        int res = 0;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        divisor = abs(divisor);
        // 若被除数为INT_MIN，令其加上除数的绝对值，并将结果加1
        // 这样之后的abs(dividend)就不会溢出
        if (dividend == INT_MIN) {
            dividend += divisor;
            res++;
        }
        dividend = abs(dividend);
        while (dividend >= divisor) {
            int tmp = divisor;
            int multiple = 1;
            while ((dividend >> 1) >= tmp) {
                tmp <<= 1;
                multiple <<= 1;
            }
            res += multiple;
            dividend -= tmp;
        }
        return (sign == 1) ? res : -res;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<pair<int, int>> pairs = {{1, 1},
                                    {-2147483648, -1},
                                    {2147483647, 1},
                                    {3, 2}};
    vector<int> expected = {1, 2147483647, 2147483647, 1};

    for (int i = 0; i < pairs.size(); i++) {
        int res = s.divide(pairs[i].first, pairs[i].second);
        if (res != expected[i]) {
            cout << pairs[i].first << " / " << pairs[i].second << " = " <<
                    res << ", expected: " << expected[i] << endl;
            continue;
        }
        cout << "Success" << endl;
    }
    return 0;
}
