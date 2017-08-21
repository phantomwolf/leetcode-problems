#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    // Right shift numbers in nums1 by n positions
    for (int i = m - 1; i >= 0; --i) {
        nums1[i + n] = nums1[i];
    }
    // Merge
    int i = n, j = 0, k = 0;
    int total = m + n;
    while (i != total && j != n) {
        if (nums1[i] < nums2[j])
            nums1[k++] = nums1[i++];
        else
            nums1[k++] = nums2[j++];
    }
    if (i == total) {
        // Still remaining elements in nums2
        while (j != n)
            nums1[k++] = nums2[j++];
    } else {
        // Still remaining elements in nums1
        while (i != total)
            nums1[k++] = nums1[i++];
    }
}

int main(int argc, char *argv[])
{
}
