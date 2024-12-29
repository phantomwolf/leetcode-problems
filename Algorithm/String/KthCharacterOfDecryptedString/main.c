#include <stdio.h>
#include <stdlib.h>


#define is_digit(c)     ((c) >= '0' && (c) <= '9')

char kth_of_decrypted(char *str, int k)
{
    char *begin = str;
    char *end = begin + 1;
    while (*begin != '\0') {
        if (is_digit(*end)) {
            char *new_begin;
            int length = (int)(end - begin);
            int repeat = strtol(end, &new_begin, 10);
            printf("begin: %c, length: %d, repeat: %ld\n", *begin, length, repeat);
            if (k <= length * repeat) {
                int index = (k - 1) % length;
                printf("index: %i\n", index);
                return *(begin + index);
            }
            k -= length * repeat;
            end = begin = new_begin;
        }
        end++;
    }
    return '\0';
}


int main()
{
    char *str;
    int k;
    char res;

    str = "a2b2c3";
    k   = 5;
    res = kth_of_decrypted(str, k);
    printf("%s, %d: %c\n", str, k, res);

    str = "ab4c2ed3";
    k   = 9;
    res = kth_of_decrypted(str, k);
    printf("%s, %d: %c\n", str, k, res);

    str = "ab4c12ed3";
    k   = 21;
    res = kth_of_decrypted(str, k);
    printf("%s, %d: %c\n", str, k, res);

    return 0;
}
