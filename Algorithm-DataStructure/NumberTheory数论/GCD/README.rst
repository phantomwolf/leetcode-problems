最大公约数
=================================
最大公约数（英语：greatest common divisor，gcd），指两个或多个整数共同具有的最大约数。此处主要介绍辗转相除法(欧几里得算法)。


辗转相除法
--------------------------
不断互相求余数，得到的余数用作下一次计算，直到不再有余数。

例如计算a = 1071和b = 462的最大公约数，首先1071 mod 462 = 147，然后462 mod 147 = 21，最后147 mod 21 = 0。21就是1071和462的最大公约数。


扩展辗转相除法
--------------------------
扩展算法不仅能求出最大公约数，还能求出系数x和y，使得::

    xa + yb = gcd(a, b)

基础情况：当a = 0时，x = 0, y = 1。

一般情况：令x1、y1为gcd(b % a, a)中的x、y值，有::

    x = y1 - ⌊b/a⌋ * x1
    y = x1

整个算法为::

    // C function for extended Euclidean Algorithm
    int gcdExtended(int a, int b, int *x, int *y)
    {
        // Base Case
        if (a == 0)
        {
            *x = 0;
            *y = 1;
            return b;
        }
     
        int x1, y1; // To store results of recursive call
        int gcd = gcdExtended(b%a, a, &x1, &y1);
     
        // Update x and y using results of recursive
        // call
        *x = y1 - (b/a) * x1;
        *y = x1;
     
        return gcd;
    }

用途：当a与b互质时(a与b的最大公约数为1)，本算法很有用。被用于RSA加密算法。
