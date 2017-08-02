#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

int min_palindrome_partition(char *s)
{
    const int len = strlen(s);
    uint8_t d[len][len];        // d[i][j]: 1 if str[i..j] is palindrome; otherwise, 0.
    int c[len];                 // c[i]: minimum number of cuts needed for str[0..i]
    for (int i = 0; i < len; ++i) {
        d[i][i] = 1;
    }
    for (int i = 0; i < len - 1; ++i) {
        d[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 0;
    }
    for (int l = 3; l <= len; ++l) {
        for (int i = 0, j = i + l - 1; j < len; ++i, ++j) {
            if (s[i] == s[j] && d[i + 1][j - 1] == 1)
                d[i][j] = 1;
            else
                d[i][j] = 0;
        }
    }

    // 对于str[0..i]，若str[j+1..i]为回文，
    // 那我们可以先将str[0..j]切成一个palindrome，
    // 再多切一下将str[j+1..i]分到后边，以达成一个palindrome partition
    for (int i = 0; i < len; ++i) {
        if (d[0][i] == 1)
            c[i] = 0;   // 因d[i][i]必为1，所以c[0]为0。
        else {
            c[i] = INT_MAX;
            for (int j = 0; j < i; ++j) {
                if (d[j + 1][i] == 1 && c[j] + 1 < c[i])
                    c[i] = c[j] + 1;
            }
        }
    }
    return c[len - 1];
}

int main(int argc, char *argv[])
{
    char *str = "ababbbabbababa";
    int res = min_palindrome_partition(str);
    printf("result: %d\n", res);

    return 0;
}
