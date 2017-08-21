#include <iostream>
#include <limits>
#include <vector>

#include "Trie.h"

using namespace std;


uint32_t max_xor_subarray(const vector<uint32_t> &nums, vector<uint32_t> &subarray)
{
    uint32_t max_xor = 0;
    Trie trie;
    vector<uint32_t> xors(nums.size() + 1);
    int l = 0, r = -1;

    xors[0] = 0;
    trie.insert(0);
    for (size_t i = 0; i < nums.size(); ++i) {
        xors[i + 1] = xors[i] ^ nums[i];
        uint32_t curr_xor = trie.query(xors[i + 1]);
        if (curr_xor > max_xor) {
            max_xor = curr_xor;
            r = i;
        }
        trie.insert(xors[i + 1]);
    }

    uint32_t tmp = max_xor ^ xors[r + 1];
    for (size_t i = 0; i <= nums.size(); ++i) {
        if (xors[i] == tmp) {
            l = i;
            break;
        }
    }
    for (int i = l; i <= r; ++i) {
        subarray.push_back(nums[i]);
    }
    return max_xor;
}

void print_result(const vector<uint32_t> &subarray, uint32_t max_xor)
{
    cout << max_xor << " = ";
    cout << subarray[0];
    for (size_t i = 1; i < subarray.size(); ++i) {
        cout << " ^ " << subarray[i];
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<uint32_t> nums1{1, 2, 3, 4};
    vector<uint32_t> nums2{8, 1, 2, 12, 7, 6};
    vector<uint32_t> nums3{4, 6};

    vector<uint32_t> subarray1;
    uint32_t max_xor1 = max_xor_subarray(nums1, subarray1);
    print_result(subarray1, max_xor1);

    vector<uint32_t> subarray2;
    uint32_t max_xor2 = max_xor_subarray(nums2, subarray2);
    print_result(subarray2, max_xor2);

    vector<uint32_t> subarray3;
    uint32_t max_xor3 = max_xor_subarray(nums3, subarray3);
    print_result(subarray3, max_xor3);

    return 0;
}
