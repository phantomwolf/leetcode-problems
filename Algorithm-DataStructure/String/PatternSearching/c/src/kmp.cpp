#include "kmp.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

void kmp_table(const string &s, const string &w, int t[])
{
    t[0] = -1;
    t[1] = 0;
    int pos = 2;
    int cnd = 0;
    while (pos < w.size()) {
        // first case: the substring continues
        if (w[pos - 1] == w[cnd]) {
            t[pos] = cnd + 1;
            cnd++;
            pos++;
        // second case: it doesn't, but we can fall back
        } else if (cnd > 0) {
            cnd = t[cnd];
        // third case: we have run out of candidates. Note cnd = 0
        } else {
            t[pos] = 0;
            pos++;
        }
    }
}


int kmp_search(const string &s, const string &w)
{
    int m = 0;      // beginning of the current match in s
    int i = 0;      // position of current character in w
    int *t = new int[w.size()];
    kmp_table(s, w, t);
    while (m + i < s.size()) {
        if (w[i] == s[m + i]) {
            if (i == w.size() - 1) {
                delete[] t;
                return m;
            }
            i++;
        } else {
            // Mismatch
            if (t[i] > -1) {
                m = m + i - t[i];
                i = t[i];
            } else {
                m++;
                i = 0;
            }
        }
    }
    delete[] t;
    return -1;
}


int main(int argc, char *argv[])
{
    int ret;
    string s("AABAC");
    string w("AB");
    cout << "Input text: ";
    cin >> s;
    cout << "Input pattern: ";
    cin >> w;
    ret = kmp_search(s, w);
    cout << "loc: " << ret << endl;

    return 0;
}
