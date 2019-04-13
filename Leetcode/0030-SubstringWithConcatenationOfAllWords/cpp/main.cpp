#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;


class Solution1
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        // special cases
        if (words.size() == 0 || s.size() < words[0].size())
            return res;
        
        // count the occurances words in "words"
        unordered_map<string, int> words_count;
        for (int i = 0; i < words.size(); i++) {
            words_count[words[i]]++;
        }

        // amount of valid words
        const int word_len = words[0].size();
        // count the occurances of words in current window 
        unordered_map<string, int> window_count;
        for (int i = 0; i < word_len; i++) {
            int left = i;   // current left boundary
            window_count.clear();
            int count = 0;
            for (int j = i; j <= s.size() - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                // j is the starting position of current word
                if (words_count[word] == 0) {
                    cout << word << " not in words" << endl;
                    // No such word. Update left boundary
                    left = j + word_len;
                    window_count.clear();
                    count = 0;
                    continue;
                }
                if (window_count[word] == words_count[word]) {
                    cout << "too many " << word << endl;
                    // remove words from current window until "word" is removed
                    string tmp;
                    do {
                        tmp = s.substr(left, word_len);
                        window_count[tmp]--;
                        count--;
                        left += word_len;
                    } while(tmp != word);
                }
                // add "word" to current window
                cout << "add " << word << " to current window" << endl;
                window_count[word]++;
                count++;
                if (count == words.size()) {
                    cout << "found answer" << endl;
                    // We found an answer
                    res.push_back(left);
                    // Prepare for next loop
                    cout << "Remove " << s.substr(left, word_len) << endl;
                    window_count[s.substr(left, word_len)]--;
                    count--;
                    left += word_len;
                }
            }
        }
        return res;
    }
};




int main(int argc, char *argv[])
{
    string s("barfoothefoobarman");
    vector<string> words{"foo", "bar"};
    vector<int> res;

    Solution1 s1;
    res = s1.findSubstring(s, words);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ", ";
    }
    cout << endl;
    

    return 0;
}
