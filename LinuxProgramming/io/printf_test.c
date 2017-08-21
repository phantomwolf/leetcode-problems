#include <stdio.h>

#define BUF_SIZE 100

void printf_test()
{
    int num;

    num = printf("printf test\n");
    printf("%d chars printed\n", num);

    FILE* fp = fopen("data.txt", "w");
    num = fprintf(fp, "fprintf test\n");
    fclose(fp);
    printf("%d chars printed to file: data.txt\n", num);

    char buf[BUF_SIZE];
    num = snprintf(buf, BUF_SIZE, "%s: This is a string~~~~", "msg");
    if (num >= BUF_SIZE) {
        puts("string is truncated");
    } else {
        puts("string isn't truncated");
    }
}
