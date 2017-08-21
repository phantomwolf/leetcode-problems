#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int hash_table[128];
        int i = 0, j;
        int length;
        fill_n(hash_table, 128, -1);
        for (j = 0; j < s.size(); ++j) {
            if (hash_table[s[j]] != -1) {
                // calculate substring length
                length = j - i;
                if (longest < length)
                    longest = length;
                while (i < hash_table[s[j]]) {
                    hash_table[s[i]] = -1;
                    ++i;
                }
                ++i;
            }
            hash_table[s[j]] = j;
        }
        // edge condition
        length = j - i;
        if (longest < length)
            longest = length;
        return longest;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwke") << endl;
    return 0;
}
