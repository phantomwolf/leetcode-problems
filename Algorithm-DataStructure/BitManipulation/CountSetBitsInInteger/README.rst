整数中有多少个bit被设为1
===========================================
Write an efficient program to count number of 1s in binary representation of an integer.

Examples

Input : n = 6
Output : 2
Binary representation of 6 is 110 and has 2 set bits

Input : n = 13
Output : 3
Binary representation of 11 is 1101 and has 3 set bits


gcc中内置的方法
------------------------------
gcc中提供内置函数::

    int __builtin_popcount (unsigned int x)

返回x中为1的bit数量。


naive方法
------------------------------
写个循环，检查每一个bit是否被设为1，数量加起来就是最终结果。设该整数共有n个bits，那么算法时间复杂度为O(n)。


Brian Kernighan算法
------------------------------
将一个数减去1，会导致其最低的被设为1的bit被置为0，该bit右边的bit都会被置为1。例如::

    00110100 - 1 =
    00110011

可见，原本最低的被设为1的bit是右边数第3位，减去1后，右边数第三位变成0，最右边的两位变成了1。将两数执行 & 操作，可将最低的被设为1的bit置为0。

重复执行上述操作，直到最终结果变为0为止。此时，循环执行了多少次，就说明整数中有多少个为1的bit。


Lookup table法
------------------------------
此方法非常耗费内存，但时间复杂度为O(1)。原理很简单，就是设置一个很大的数组，然后把结果直接存进去，需要时用下标取用就可以。不过这样一个数组是可以在编译时生成的，不耗费运行时间。

代码如下::

    static const unsigned char BitsSetTable256[256] = 
    {
    #   define B2(n) n,     n+1,     n+1,     n+2
    #   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
    #   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
        B6(0), B6(1), B6(1), B6(2)
    };
    
    unsigned int v; // count the number of bits set in 32-bit value v
    unsigned int c; // c is the total bits set in v
    
    // Option 1:
    c = BitsSetTable256[v & 0xff] + 
        BitsSetTable256[(v >> 8) & 0xff] + 
        BitsSetTable256[(v >> 16) & 0xff] + 
        BitsSetTable256[v >> 24]; 
    
    // Option 2:
    unsigned char * p = (unsigned char *) &v;
    c = BitsSetTable256[p[0]] + 
        BitsSetTable256[p[1]] + 
        BitsSetTable256[p[2]] +	
        BitsSetTable256[p[3]];
    
    
    // To initially generate the table algorithmically:
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
      BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
    }
