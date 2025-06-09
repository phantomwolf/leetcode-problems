#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }

        int matched = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) {
                matched++;
            }
        }
        if (matched == 26) {
            return true;
        }

        int left = 0, right = s1.size();
        while (right < s2.size()) {
            char cr = s2[right];
            right++;
            if (count2[cr-'a'] == count1[cr-'a']) {
                matched--;
            }
            count2[cr-'a']++;
            if (count2[cr-'a'] == count1[cr-'a']) {
                matched++;
            }

            char cl = s2[left];
            left++;
            if (count2[cl-'a'] == count1[cl-'a']) {
                matched--;
            }
            count2[cl-'a']--;
            if (count2[cl-'a'] == count1[cl-'a']) {
                matched++;
            }
            if (matched == 26) {
                return true;
            }
        }
        return false;
    }
};