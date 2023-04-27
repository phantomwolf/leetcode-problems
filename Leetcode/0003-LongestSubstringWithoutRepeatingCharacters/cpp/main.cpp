#include <iostream>
#include <vector>
#include <string>

class Solution1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> index(256);
        std::fill_n(index.begin(), 256, -1);
        int l = 0, r;
        int longest = 0;
        for (r = 0; r < s.size(); r++) {
            if (index[s[r]] != -1) {
                // Add s[r] to sliding window will result in duplication
                int length = r - l;
                if (length > longest)
                    longest = length;
                while (l <= index[s[r]]) {
                    index[s[l]] = -1;
                    l++;
                }
            }
            index[s[r]] = r;
        }
        int length = r - l;
        if (length > longest) {
            longest = length;
        }
        return longest;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int count[256] = {0};
        int repeated = 0;   // number of repated characters in current window
        int l = 0;
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            if (count[s[i]] == 2) {
                repeated++;
            }
            if (repeated == 0 && i - l + 1 > longest) {
                longest = i - l + 1;
            }
            while (l < i && repeated > 0) {
                count[s[l]]--;
                if (count[s[l]] == 1) {
                    repeated--;
                }
                l++;
            }
        }
        return longest;
    }
};

int main()
{
    Solution1 s;
    std::cout << s.lengthOfLongestSubstring("pwwke") << std::endl;
    return 0;
}
