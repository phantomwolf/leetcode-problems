#include "Solution3.h"

Solution3::Solution3()
{
    //ctor
}

Solution3::~Solution3()
{
    //dtor
}

string Solution3::longestPalindrome(string s)
{
    bool **P = new bool*[s.size()];
    for (int i = 0; i < s.size(); ++i) {
        P[i] = new bool[s.size()];
    }
    // Find the longest palindrome string
    int longest = 1, pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        P[i][i] = true;
    }
    if (s.size() >= 2) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i+1]) {
                P[i][i+1] = true;
                longest = 2;
                pos = i;
            } else {
                P[i][i+1] = false;
            }
        }
    }
    for (int len = 3; len <= s.size(); ++len) {
        for (int i = 0; i <= s.size() - len; ++i) {
            int j = i + len - 1;
            if (P[i+1][j-1] == true && s[i] == s[j]) {
                P[i][j] = true;
                if (len > longest) {
                    longest = len;
                    pos = i;
                }
            } else {
                P[i][j] = false;
            }
        }
    }
    return s.substr(pos, longest);
}
