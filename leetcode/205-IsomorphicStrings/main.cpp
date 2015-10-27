#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s2t[128] = {0};
        char t2s[128] = {0};
        for (int i=0; i < s.size(); ++i) {
            if (s2t[s[i]] == 0) {
                s2t[s[i]] = t[i];
            }
            if (t2s[t[i]] == 0) {
                t2s[t[i]] = s[i];
            }
            if (s[i] != t2s[t[i]] || t[i] != s2t[s[i]]) {
                cout << s2t[s[i]] << " != " << t2s[t[i]] << endl;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("exg", "add") << endl;
    return 0;
}
