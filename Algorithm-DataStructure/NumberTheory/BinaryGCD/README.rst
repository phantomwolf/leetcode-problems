Stein’s algorithm/Binary GCD algorithm
==========================================================
Stein’s algorithm/Binary GCD algorithm是一个用于计算两个非负整数的最大公约数的算法，它将辗转相除法里的除法运算用算术位移、比较、减法代替。

Examples::

    Input: a = 17, b = 34
    Output : 17

    Input: a = 50, b = 49
    Output: 1


步骤
--------------------------------

1. 如果a与b均为0，则最大公约数为0，gcd(0, 0) = 0。
2. gcd(a, 0) = a，gcd(0, b) = b。因为0能被任何数整除。
3. 若a与b同为偶数，gcd(a, b) = 2 * gcd(a/2, b/2)，因为2肯定是a与b的公约数。乘以2可以用位移操作替代。
4. 若a为偶数，b为奇数，gcd(a, b) = gcd(a/2, b)。同理，若a为奇数，b为偶数，gcd(a, b) = gcd(a, b/2)。因为2肯定不是奇数的公约数。
5. 若a与b同为奇数，gcd(a, b) = gcd(|a-b|/2, b)。|a-b|肯定为偶数。
6. 重复3-5步，直到a = b或a = 0。这时，最大公约数为power(2, k) * b，k为第二步中除掉的2的次数。
