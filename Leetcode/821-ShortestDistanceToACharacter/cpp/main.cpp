#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        unsigned int length = S.size();
        vector<int> R(length);
        int prevC = 0;
        // Handle left-most C
        while (S[prevC] != C) {
            prevC++;
        }
        for (int j=0; j <= prevC; j++) {
            R[j] = prevC - j;
        }
        // Handle remaining ones
        for (int i=prevC+1; i < length; i++) {
            if (S[i] != C) {
                R[i] = i - prevC;
                continue;
            }
            for (int j = (prevC + i)/2 + 1; j <= i; j++) {
                R[j] = i - j;
            }
            prevC = i;
        }
        return R;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> r = s.shortestToChar("baka", 'a');
    cout << "Result:" << endl;
    for (int i=0; i < r.size(); i++) {
        cout << r[i] << ",";
    }
    cout << endl;
    return 0;
}
