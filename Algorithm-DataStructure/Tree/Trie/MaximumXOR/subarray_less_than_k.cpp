#include <iostream>
#include <limits>
#include <vector>

#include "Trie.h"

using namespace std;


uint32_t count_subarray_xor_less_than_k(const vector<uint32_t> &nums, uint32_t k)
{
    Trie trie;
    uint32_t pre_xor = 0;
    uint32_t res = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        cout << "Inserting: " << pre_xor << endl;
        trie.insert(pre_xor);
        pre_xor ^= nums[i];
        res += trie.count(pre_xor, k);
    }
    trie.print();
    return res;
}


int main(int argc, char *argv[])
{
    vector<uint32_t> nums{1, 2, 3, 4};
    uint32_t res = count_subarray_xor_less_than_k(nums, numeric_limits<uint32_t>::max());
    cout << "result: " << res << endl;

    return 0;
}
