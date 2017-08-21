#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool is_prime(unsigned int n, int k)
{
    // 边界情况。因为此算法要求n > 3。
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    // 偶数直接返回false
    if (n & 1 == 0)
        return false;

    // 测试k次
    while (k > 0) {
        // 从[2, n-2]中随机选择一个数
        int a = 2 + rand() * (n - 4);
        if (pow(a, n - 1) % n != 1)
            return false;
        k--;
    }
    return true;
}
