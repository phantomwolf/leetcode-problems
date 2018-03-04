以整数为输入的hash算法
=================================
设m为哈希表的大小，k为要hash的整数，h(k)为k的hash值。

mod法(divison hash)
------------------------------
h(k) = k mod m

当使用这种方法时，需要避免特定的m值，比如2的幂，因为k mod 2^b仅仅选择了k的较低的b个bit。远离2的幂的质数一般是m较好的选择，比如701。

Knuth建议的改进：h(k) = k(k+3) mod m

乘法(multiplication hash)
------------------------------
方法如下：

- 将key乘以常数A，得到s，0 < A < 1。Knuth建议：A = (sqrt(5)-1)/2 = 0.6180339887
- 将s的小数部分提取出来，得到x。
- 将m与x相乘，得到h(k)

即 h(k) = floor(m * (kA - floor(kA)))。

在这种情况下，m的值并非至关重要。

https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
https://www.cs.auckland.ac.nz/software/AlgAnim/hash_func.html


以字符串为输入的hash算法
=================================
djb2
-----------------
算法过程如下：

- hash = 5381;
- 对于字符串中的每个字符c，令hash = hash * 33 + c;
- 处理完最后的字符后，返回hash。

至于为什么数字33比其它数字更好，并没有一个明确的说明。

sdbm
-----------------
算法过程与上一个类似：

- hash = 0;
- 对字符串中的每个字符c，令：hash = hash * 65599 + c;
- 处理完所有字符后，返回hash。
