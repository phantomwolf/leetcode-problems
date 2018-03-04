#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define SIZE    10


#define swap(a, b) \
        do { typeof(a) __tmp = a; a = b; b = __tmp; } while (0)

int partition(int nums[], int left, int right, int p);

int median5(int nums[], int left, int right);

int pivot(int nums[], int left, int right);

int intro_select(int nums[], int left, int right, int k);

void print_array(int array[], int size, int l, int r, int p)
{
    int i = 0;
    while (i < l) {
        printf("%6d", array[i]);
        ++i;
    }
    printf("[");
    while (i < p) {
        printf("%6d", array[i]);
        ++i;
    }
    printf(" |%d| ", array[i]);
    ++i;
    while (i <= r) {
        printf("%6d", array[i]);
        ++i;
    }
    printf("]");
    while (i < size) {
        printf("%6d", array[i]);
        ++i;
    }
    puts("");
}

/* pivot is an index */
int partition(int nums[], int left, int right, int p)
{
    if (left == right)
        return left;
    // Swap pivot to the beginning
    if (p != left) {
        swap(nums[left], nums[p]);
    }
    int i = left + 1, j = right;
    while (1) {
        while (nums[i] > nums[left])
            ++i;
        while (nums[j] < nums[left])
            --j;
        if (i >= j) {
            swap(nums[left], nums[j]);
            return j;
        }
        if (nums[i] != nums[j]) {
            swap(nums[i], nums[j]);
        }
        ++i;
        --j;
    }
    return -1;
}

/* Get median of at most 5 elements */
int median5(int nums[], int left, int right)
{
    int i, j;
    // Do insertion sort to find median
    // Note: Since this problem requires placing large numbers to the left side,
    //       so here we put large numbers to the left
    for (i = left + 1; i <= right; ++i) {
        int tmp = nums[i];
        for (j = i - 1; j >= left && nums[j] < tmp; --j) {
            nums[j+1] = nums[j];
        }
        nums[j+1] = tmp;
    }

    printf("insertion sort: ");
    for (int i = left; i <= right; ++i) {
        printf("%d, ", nums[i]);
    }
    puts("");

    return (left + right) / 2;
}

/* Find a nice pivot index. The actual median-of-medians algorithm */
int pivot(int nums[], int left, int right)
{
    // for 5 or less elements, just get median
    if (right - left < 5) {
        return median5(nums, left, right);
    }
    // To find median of medians, repeatedly calculate median of 5 elements groups
    // and swap them to the beginning of the array, then calculate their median
    // by recursively calling intro_select
    for (int i = left; i <= right; i += 5) {
        int sub_right = left + 4;
        if (sub_right > right)
            sub_right = right;
        // Calculate median of 5 elements
        int median = median5(nums, left, sub_right);
        // Swap it to the beginning of the array
        swap(nums[median], nums[left + (i-left)/5]);
    }
    // Calculate median of medians
    return intro_select(nums, left, left + ceil((right - left) / 5.0) - 1, left + (right - left) / 10 + 1);
}

/* Select kth largest number, return its index */
int intro_select(int nums[], int left, int right, int k)
{
    int p = pivot(nums, left, right);
    p = partition(nums, left, right, p);
    while (p != k - 1) {
        printf("k: %d  ", k);
        print_array(nums, SIZE, left, right, p);
        if (p < k - 1) {
            left = p + 1;
        } else {
            right = p - 1;
        }
        p = pivot(nums, left, right);
        p = partition(nums, left, right, p);
    }
    return p;
}



int main()
{
    srand(time(NULL));

    int nums[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % 1000;
    }

    int k = rand() % SIZE + 1;
    printf("Calculating %dth largest num...\n", k);
    int p = intro_select(nums, 0, SIZE - 1, k);
    // Confirm
    for (int i = 0; i < p; ++i) {
        if (nums[i] < nums[p])
            printf("%d(%d), ", nums[i], i);
    }
    puts("");

    for (int i = p + 1; i < SIZE; ++i) {
        if (nums[i] > nums[p])
            printf("%d(%d), ", nums[i], i);
    }
    puts("");

    // Print array
    print_array(nums, SIZE, 0, SIZE - 1, p);


    return 0;
}
