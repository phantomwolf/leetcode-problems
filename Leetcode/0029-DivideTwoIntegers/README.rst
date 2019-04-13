29. Divide Two Integers 
=============================================
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.


Naive Solution
---------------------------------------
除法的意义是dividend(被除数)可以由多少个divisor(除数)相加而组成。因此最简单的算法是，不断从dividend中减去divisor，直到结果为0。减去divisor的次数就是我们要的结果。

Better Solution
---------------------------------------
基本思路：我们没必要每次只减去一个divisor，可以将divisor不断乘以2(不断左移)，再令dividend减去它，可以大幅减少执行减法的次数。时间复杂度应该是对数。

假设我们令15除以3，因此15是被除数(dividend)而3是除数(divisor)::

    dividend - divisor = 15 - 3 = 12 > 0

观察可知，我们可以增大divisor来减少执行减法的次数，将divisor左移1位，得到6，有::

    dividend - divisor = 15 - 6 = 9 > 0

还可以继续增大divisor，再将divisor左移1位，得到12，有::

    dividend - divisor = 15 - 12 = 3 > 0

再次增大divisor，得到24，有::

    dividend - divisor = 15 - 24 = -9 < 0

可知最大的可行的divisor就是12 = 3 * 4。怎样得到这个4呢？我们设置一个变量exp = 1，每次左移divisor，我们都将exp左移，最后得到的就是4。

这相当于dividend可以写成：15 = 3 * 4 + 3。还剩下一个余数3。我们对3再次重复上述过程(即divisor从3重新开始)，得到3 = 3 * 1。最终结果为4 + 1 = 5。


Binary Solution
---------------------------------------
时间复杂度O(1)。

假设最终的结果为ret，其二进制形式为::

    ret = a0 * 2^0 + a1 * 2^1 + a2 * 2^2 + ... + a31 * 2^31。ai = 0或1，i = 0, 1, ..., 31

设被除数B与除数A均为非负整数，则::

    equation1: A * ret = A * (a0 * 2^0 + a1 * 2^1 + a2 * 2^2 + ... + a31 * 2^31) = B

当equation1两边均被除以2^31时，有::

    A * a31 = B >> 31，即 a31 = (B >> 31) / A

若(B >> 31) > A，那么a31 = 1，否则a31 = 0。

同理，当equation1两边均被除以2^30时，有::

    A * a30 + A * (a31 * 2) = B >> 30，即 a30 = ((B >> 30) - A * (a31 * 2)) / A

而(B >> 30) - A * (a31 * 2)可以被重写为::

    (B - ((A * a31 * 2) << 30)) >> 30 = (B - ((A * a31) << 31)) >> 30

令B' = B - (a31 * A << 31)，则式子简化为::

    a30 = (B' >> 30) / A

若(B' >> 30) > A，那么a30 = 1，否则a30 = 0。

同理，可以得到a29 = ((B-a31*A<<31-a30*A<<30)>>29)/A，令B'' = B' - a30*A << 30，有::

    a29 = (B'' >> 29) / A
