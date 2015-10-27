#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        while (i < s.size() && j < p.size()) {
            if (j+1 < p.size() && p[j+1] == '*') {
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
