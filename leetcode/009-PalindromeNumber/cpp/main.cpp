#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int div = 1;
        while (x/10 >= div) {
            div *= 10;
        }
        while (x > 0) {
            // get first digit
            int left = x/div;
            // get last digit
            int right = x%10;
            if (left != right)
                return false;
            // remove the first and last digit from x
            x = (x%div)/10;
            div /= 100;
        }
        return true;
    }
};

int main()
{
    Solution s;
    if (s.isPalindrome(12321)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
