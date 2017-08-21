#include <stdio.h>

int power(int x, unsigned int y)
{
    if (x == 0)
        return 0;
    if (y == 0)
        return 1;

    int tmp = power(x, y / 2);
    if (y & 1)
        return x * tmp * tmp;
    else
        return tmp * tmp;
}

int main(int argc, char *argv[])
{
    int x = 2, y = 10;
    int res = power(x, y);
    printf("%d^%d = %d\n", x, y, res);

    return 0;
}
