#include <stdio.h>
#include <stdbool.h>

// Find the index of the possible candidate
int find_cand_index(char a[], int size)
{
    int cand_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[cand_index] == a[i])
            count++;
        else
            count--;

        if (count == 0) {
            cand_index = i;
            count = 1;
        }
    }
    return cand_index;
}

bool is_majority(char a[], int  size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == cand)
            count++;
    }
    if (count > size/2)
        return true;
    else
        return false;
}


int main()
{
    char a[13] = {'A', 'A', 'A', 'C', 'C', 'B', 'B', 'C', 'C', 'C', 'B', 'C', 'C'};
    int cand_index = find_cand_index(a, 13);
    printf("Possible candidate: %c\n", a[cand_index]);
    if (is_majority(a, 13, a[cand_index]))
        printf("Majority element: %c\n", a[cand_index]);
    else
        printf("Majority element not found\n");

    return 0;
}
