#include <stdio.h>


void print_binary(int num)
{
    for (unsigned int i = 1 << 31; i > 0; i >>= 1) {
        if (i & num)
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}


int main(int argc, char *argv[])
{
    print_binary(7);

    return 0;
}
