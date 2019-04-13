#include <stdio.h>
#include <stdbool.h>



bool circularArrayLoop(int *nums, int numsSize)
{
    if (numsSize == 0)
        return false;
    int slow = 0, fast = 0;
    do {
        int tmp = (fast + nums[fast]) % numsSize;
        fast = (tmp < 0) ? tmp + numsSize : tmp;
        if (nums[fast] % numsSize != 0) {
            tmp = (fast + nums[fast]) % numsSize;
            fast = (tmp < 0) ? tmp + numsSize : tmp;
        }
        tmp = (slow + nums[slow]) % numsSize;
        slow = (tmp < 0) ? tmp + numsSize : tmp;
    } while (nums[fast] % numsSize != 0 && slow != fast);

    if (nums[fast] % numsSize != 0) {
        // Loop detected, but we still have to make sure
        // it's either forward only or backward.
        int direction = (nums[slow] > 0) ? 1 : -1;

        int tmp = (slow + nums[slow]) % numsSize;
        slow = (tmp < 0) ? tmp + numsSize : tmp;
        while (slow != fast) {
            if (direction == 1 && nums[slow] < 0)
                break;
            else if (direction == -1 && nums[slow] > 0)
                break;
            tmp = (slow + nums[slow]) % numsSize;
            slow = (tmp < 0) ? tmp + numsSize : tmp;
        }
        if (slow == fast) {
            return true;
        }
    }
    return false;
}


int main(int argc, char *argv[])
{
    int nums[] = {3, 1, 2};
    int numsSize = 3;
//    int nums[] = {-1, 2};
//    int numsSize = 2;
    if (circularArrayLoop(nums, numsSize) == true) {
        puts("Loop detected");
    } else {
        puts("No loop detected");
    }

    return 0;
}
