#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRS_SIZE 0


char *longestCommonPrefix(char **strs, int strsSize) {
    char *base;
    char *res;
    if (strsSize <= 0) {
        /* Empty input */
        res = (char *)malloc(sizeof(char));
        res[0] = '\0';
        return res;
    }
    base = strs[0];
    int prefixLength = strlen(base);
    for (int i=1; i < strsSize; ++i) {
        for (int j=0; j < prefixLength; ++j) {
            if (base[j] != strs[i][j])
                prefixLength = j;
        }
    }
    /* Create buffer and return substr */
    res = (char *)malloc(sizeof(char) * (prefixLength + 1));
    memcpy((void *)res, (void *)base, sizeof(char) * prefixLength);
    res[prefixLength] = '\0';
    return res;
}

int main()
{
    char *strs[STRS_SIZE] = { "linux-is_good",
        "linux-is_bad",
        "linux-is_big",
        "linux-isn't ",
    };
    int strsSize = STRS_SIZE;

    char *prefix = longestCommonPrefix(strs, strsSize);
    printf("prefix: %s\n", prefix);

    return 0;
}
