#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == numeric_limits<int>::min() && divisor == -1)
            return numeric_limits<int>::max();

        int res = 0;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0))
            sign = -1;
        if (dividend > 0)
            dividend = -dividend;
        if (divisor > 0)
            divisor = -divisor;

        dividend -= divisor;
        while (dividend <= 0) {
            dividend -= divisor;
            res++;
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
