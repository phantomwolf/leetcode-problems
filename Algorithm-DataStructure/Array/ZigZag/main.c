#include <stdio.h>


#define SWAP(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


void zig_zag(int nums[], size_t n)
{
    char flag = 1;
    for (size_t i = 1; i < n; ++i) {
        if ((flag == 1 && nums[i - 1] > nums[i]) ||
            (flag == 0 && nums[i - 1] < nums[i]))
            SWAP(nums[i - 1], nums[i]);
        flag = !flag;
    }
}


int main()
{
    int nums[] = {4, 3, 7, 8, 6, 2, 1};
    size_t n   = sizeof(nums) / sizeof(int);

    zig_zag(nums, n);

    printf("zig zag: ");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", nums[i]);
    }
    puts("");

    return 0;
}
