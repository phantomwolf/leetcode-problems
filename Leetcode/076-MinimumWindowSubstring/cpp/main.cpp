#include <iostream>
#include <limits>
#include <string>


using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.size();
        int t_length = t.size();
        if (s_length < t_length)
            return "";

        int s_count[128] = {0};
        int t_count[128] = {0};
        // record the occurrances of chars in t
        for (int i = 0; i < t_length; ++i) {
            t_count[t[i]]++;
        }

        int start = -1, end = -1;
        int min_length = numeric_limits<int>::max();
        int count = 0;
        for (int i = 0, j = 0; j < s_length; ++j) {
            s_count[s[j]]++;
            if (s_count[s[j]] <= t_count[s[j]]) {
                count++;
            }
            if (count == t_length) {
                while (s_count[s[i]] > t_count[s[i]]) {
                    s_count[s[i]]--;
                    i++;
                }
                if (min_length > j - i + 1) {
                    min_length = j - i + 1;
                    start = i;
                    end = j;
                }
                s_count[s[i]]--;
                count--;
                i++;
            }
        }
        if (min_length == numeric_limits<int>::max())
            return "";
        cout << "min length: " << min_length << endl;
        return s.substr(start, end - start + 1);
    }
};


int main(int argc, char *argv[])
{
    string s = "this is a test string";
    string t = "tist";

    Solution sol;
    cout << "result: " << sol.minWindow(s, t) << endl;
    return 0;
}
