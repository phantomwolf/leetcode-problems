#include <stdio.h>

int power(int x, int y)
{
    int res = 1;     // Initialize result

    int orig = x;
    int x_exp = 1;
    int res_exp = 0;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1) {
            res *= x;
            printf("res = %d^%d * %d^%d = %d^%d\n",
                   orig, res_exp, orig, x_exp,
                   orig, res_exp + x_exp);
            res_exp += x_exp;
        }
 
        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
        x_exp += x_exp;
        printf("x = %d^%d\n", orig, x_exp);
    }
    return res;
}


int main()
{
    int x = 2, y = 8;
    int res = power(x, y);
    printf("result: %d^%d = %d\n", x, y, res);

    return 0;
}
