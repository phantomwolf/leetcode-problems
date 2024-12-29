#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

void init_bad_char_table(int bad_char[], int size, char *pattern)
{
    int plen = strlen(pattern);
    for (int i = 0; i < size; ++i) {
        bad_char[i] = plen;
    }
    for (int i = 0; pattern[i] != '\0'; ++i) {
        bad_char[pattern[i]] = i;
    }
}

void init_good_suffix_table(int good_suffix[], char *pattern)
{
    int plen = strlen(pattern);
    int prefix_index = plen;
    for (int i = plen - 1; i >= 0; --i) {
        good_suffix[i] = prefix_index;
        if (pattern[i] == pattern[plen - 1 - i] && prefix_index == i + 1)
            prefix_index = i;
    }

    printf("1st: ");
    for (int i = 0; i < 4; ++i) {
        printf("%d, ", good_suffix[i]);
    }
    puts("");

    for (int i = 0; i < plen - 1; ++i) {
        int j = plen - 1, k = 0;
        while (k < i && pattern[j] == pattern[i - k]) {
            --j;
            ++k;
        }
        if (pattern[plen - 1] == pattern[i])
            good_suffix[j] = plen - 1 - i;
    }
    good_suffix[plen - 1] = 0;

    printf("2nd: ");
    for (int i = 0; i < 4; ++i) {
        printf("%d, ", good_suffix[i]);
    }
    puts("");
}


int main(int argc, char *argv[])
{
    char *pattern = "PPAPP";
    int good_suffix[4];
    init_good_suffix_table(good_suffix, pattern);
    return 0;
}
