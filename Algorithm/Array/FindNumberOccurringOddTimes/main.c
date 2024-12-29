#include <stdio.h>


// Method 2: XOR
int get_odd_occurrence(int ar[], int ar_size)
{
    int res = 0;
    for (int i = 0; i < ar_size; i++) {
        res = res ^ ar[i];
    }
    return res;
}

int main()
{
    int ar[13] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int odd = get_odd_occurrence(ar, 13);
    printf("odd occurence: %d\n", odd);
    return 0;
}
