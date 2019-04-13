#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    inline int index(char c) {
        return c - 'a';
    }

    bool isAnagram(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if (s_len != t_len)
            return false;

        int chars = 0;
        int count[26] = {0};
        // scan string s
        for (int i = 0; i < s_len; ++i) {
            if (count[index(s[i])] == 0)
                chars++;
            count[index(s[i])]++;
        }
        // scan string t
        for (int i = 0; i < t_len; ++i) {
            if (count[index(t[i])] == 0)
                return false;
            else if (count[index(t[i])] == 1)
                chars--;
            count[index(t[i])]--;
        }
        return (chars == 0) ? true : false;
    }
};
