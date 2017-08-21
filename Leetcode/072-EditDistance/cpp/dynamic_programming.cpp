#include <iostream>
#include <string>
#include <limits>

using namespace std;


void backtrace(const string &word1, const string &word2, char **s, int i, int j)
{
    if (i == 0 && j == 0) {
        return;
    }
    if (s[i][j] == 'i') {
        backtrace(word1, word2, s, i, j - 1);
        cout << "insert " << word2[j - 1] << " at " << i - 1  << endl;
    } else if (s[i][j] == 'd') {
        backtrace(word1, word2, s, i - 1, j);
        cout << "remove: " << word1[i - 1] << " at " << i << endl;
    } else if (s[i][j] == 'r') {
        backtrace(word1, word2, s, i - 1, j - 1);
        cout << "replace: " << word1[i - 1] << " => " << word2[j - 1] << " at " << i << endl;
    } else if (s[i][j] == 'n') {
        backtrace(word1, word2, s, i - 1, j - 1);
    }
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();

        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;

        int **d = new int*[len1 + 1];
        char **s = new char*[len1 + 1];
        for (int i = 0; i <= len1; ++i) {
            d[i] = new int[len2 + 1];
            s[i] = new char[len2 + 1];
        }

        for (int i = 0; i <= len1; ++i) {
            d[i][0] = i;
            s[i][0] = 'd';
        }
        for (int j = 0; j <= len2; ++j) {
            d[0][j] = j;
            s[0][j] = 'i';
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1];
                    s[i][j] = 'n';
                    continue;
                }
                int tmp;
                int min = numeric_limits<int>::max();
                char op = 'n';
// 要将str1[0..i-1]转换为str2[0..j-1]，可先将str1[0..i-1]转换为str2[0..j]，再删掉一个字符
                if (min > (tmp = 1 + d[i - 1][j])) {
                    min = tmp;
                    op = 'd';
                }
// 要将str1[0..i-1]转换为str2[0..j-1]，可将str1[0..i-1]转换为str2[0..j-1]，再插入str2[j-1]
                if (min > (tmp = 1 + d[i][j - 1])) {
                    min = tmp;
                    op = 'i';
                }
// 要将str1[0..i-1]替换为str2[0..j-1]，可将str1[0..i-1]替换为str2[0..j-1]，再将str1[i-1]题换为str2[j-1]
                if (min > (tmp = 1 + d[i - 1][j - 1])) {
                    min = tmp;
                    op = 'r';
                }
                d[i][j] = min;
                s[i][j] = op;
            }
        }

        backtrace(word1, word2, s, len1, len2);

        int res = d[len1][len2];
        for (int i = 0; i <= len1; ++i) {
            delete[] d[i];
            delete[] s[i];
        }
        delete[] d;
        delete[] s;

        return res;
    }
};



int main(int argc, char *argv[])
{
    string word1("distance");
    string word2("springbok");
    cout << word1  << " => " << word2 << endl;

    Solution s;
    cout << "min operations: " << s.minDistance(word1, word2) << endl;

    return 0;
}
