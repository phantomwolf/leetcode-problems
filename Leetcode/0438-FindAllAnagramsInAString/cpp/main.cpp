#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    inline int index(char c) {
        return c - 'a';
    }

    vector<int> findAnagrams(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        vector<int> res;
        if (s_len < p_len)
            return res;

        // Record the count of characters
        int p_count[26] = {0};
        int s_count[26] = {0};
        // Record how many s_count[i] == p_count[i].
        // When count == 26, it's an anagram
        int count = 0;
        // scan string p and first p_len characters in s
        for (int i = 0; i < p_len; ++i) {
            p_count[index(p[i])]++;
            s_count[index(s[i])]++;
        }
        for (int i = 0; i < 26; ++i) {
            if (s_count[i] == p_count[i])
                count++;
        }
        if (count == 26)
            res.push_back(0);
        for (int i = 1, j = p_len; j < s_len; ++i, ++j) {
            int diff;

            s_count[index(s[i - 1])]--;
            diff = p_count[index(s[i - 1])] - s_count[index(s[i - 1])];
            if (diff == 0)
                count++;
            else if (diff == 1)
                count--;

            s_count[index(s[j])]++;
            diff = p_count[index(s[j])] - s_count[index(s[j])];
            if (diff == 0)
                count++;
            else if (diff == -1)
                count--;

            if (count == 26)
                res.push_back(i);
        }
        return res;
    }
};
