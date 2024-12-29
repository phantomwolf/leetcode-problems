#include <algorithm>
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// Merge 2 sorted subarray nums[low..mid] and nums[mid+1..high] to aux[low..high]
void merge(int *nums, int low, int mid, int high, int *aux) {
    cout << "merge(nums, " << low << ", " << mid << ", " << high << ", aux)" << endl;
    if (nums[mid] < nums[mid+1]) {
        // nums[low..high] is already sorted, just copy(optimization 2)
        std::memcpy(aux + low, nums + low, sizeof(int) * (high - low + 1));
        return;
    }
    // Merge them
    int i = low, j = mid+1;
    int k = low;
    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            aux[k++] = nums[i++];
        } else {
            aux[k++] = nums[j++];
        }
    }
    if (i > mid) {
        std::memcpy(aux + k, nums + j, sizeof(int) * (high - j + 1));
    } else if (j > high) {
        std::memcpy(aux + k, nums + i, sizeof(int) * (mid - i + 1));
    }
}

void mergeSort(int *nums, int length) {
    int *aux = new int[length];
    bool reverse = false;
    for (int size = 2; size < length * 2; size *= 2) {
        int low = 0;
        int high = std::min(low + size - 1, length-1);
        int mid = low + size/2 - 1;
        while (low < length) {
            if (!reverse) {
                merge(nums, low, mid, high, aux);
            } else {
                merge(aux, low, mid, high, nums);
            }
            if (!reverse) {
                cout << "aux: ";
                for (int i = 0; i < length; i++) {
                    cout << aux[i] << ", ";
                }
                cout << endl;
            } else {
                    cout << "nums: ";
                    for (int i = 0; i < length; i++) {
                        cout << nums[i] << ", ";
                    }
                    cout << endl;
            }
            low += size;
            high = std::min(low + size - 1, length-1);
            mid = (low + high) / 2;
        }
        reverse = !reverse;
    }
    if (!reverse) {
        std::memcpy(nums, aux, sizeof(int) * length);
    }
    delete[] aux;
}


int main(int argc, char *argv[]) {
    int nums[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    mergeSort(nums, 10);
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        cout << nums[i] << endl;
    }
}
