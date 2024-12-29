#include <stdio.h>


// 辗转相除法(欧几里得算法)
int gcd(int a, int b)
{
    while (b != 0) {
        register int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int gcd_extended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
    }
    int x1, y1; // store results of recursive call
    int gcd = gcd_extended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}


int main(int argc, char *argv[])
{
    int a = 1071;
    int b = 462;
    int res = gcd(a, b);
    printf("The greatest common divisor of a and b is: %d\n", res);

    return 0;
}
