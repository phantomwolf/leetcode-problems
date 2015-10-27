#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool isMatch(char *s, char *p)
{
    size_t plen = strlen(p);
    size_t slen = strlen(s);
    bool **f = (bool **)malloc(sizeof(bool *) * (plen + 1));
    for (int i = 0; i < plen + 1; ++i) {
        f[i] = (bool *)malloc(sizeof(bool) * (slen + 1));
    }

    f[0][0] = true;
    for (int j = 1; j <= slen; ++j) {
        f[0][j] = false;
    }
    for (int i = 1; i <= plen; ++i) {
        f[i][0] = (p[i-1] == '*') ? f[i-1][0] : false;
    }
    for (int i = 1; i <= plen; ++i) {
        for (int j = 1; j <= slen; ++j) {
            if (p[i-1] == '*') {
                f[i][j] = f[i-1][j] || f[i][j-1];
            } else if (p[i-1] == '?' || p[i-1] == s[j-1]) {
                f[i][j] = f[i-1][j-1];
            } else {
                f[i][j] = false;
            }
        }
    }

    bool ret = f[plen][slen];
    for (int i = 0; i < plen + 1; ++i) {
        free(f[i]);
    }
    free(f);
    return ret;
}

int main(int argc, char *argv[])
{
    char *strs[7] = {"", "aa", "aaa", "aa", "aa", "ab", "aab"};
    char *ptns[7] = {"", "aa", "aa", "*", "a*", "?*", "c*a*b*"};
    for (int i = 0; i < 7; ++i) {
        bool ret;
        ret = isMatch(strs[i], ptns[i]);
        if (ret == true) {
            printf("%d. %s <=> %s: true\n", i, ptns[i], strs[i]);
        } else {
            printf("%d. %s <=> %s: false\n", i, ptns[i], strs[i]);
        }
    }


    return 0;
}
