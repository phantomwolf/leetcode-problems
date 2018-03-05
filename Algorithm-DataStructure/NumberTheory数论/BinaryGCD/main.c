#include <stdio.h>


#define SWAP(a, b) \
        do { register typeof(a) __tmp = (b); (b) = (a); (a) = __tmp; } while (0);

int binary_gcd(int a, int b)
{
    /* GCD(0, b) == b; GCD(a,0) == a, GCD(0,0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    /* Finding K, where K is the greatest power of 2
     * that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k) {
        a >>= 1;
        b >>= 1;
    }
    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;
    /* From here on, 'a' is always odd */
    do {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;
        /* Now a and b are both odd. Swap if necessary
         * so a <= b, then set b = b - a (which is even).*/
        if (a > b)
            SWAP(a, b);
        b -= a;
    } while (b != 0);
    /* restore common factors of 2 */
    return a << k;
}


int main(int argc, char *argv[])
{
    int res;
    int a, b;
    a = 17;
    b = 34;
    res = binary_gcd(a, b);
    printf("gcd of %d and %d is: %d\n", a, b, res);

    a = 50;
    b = 49;
    res = binary_gcd(a, b);
    printf("gcd of %d and %d is: %d\n", a, b, res);

    return 0;
}
