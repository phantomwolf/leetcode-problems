#include <vector>
#include <iostream>
#include <limits>

#include "Trie.h"

using namespace std;


uint32_t max_xor_of_two(const vector<int> &nums, vector<uint32_t> &buffer)
{
    Trie trie;
    uint32_t max_xor = numeric_limits<uint32_t>::min();

    buffer.reserve(2);
    trie.insert(nums[0]);
    for (size_t i = 1; i < nums.size(); ++i) {
        uint32_t curr_xor      = trie.query(nums[i]);
        if (curr_xor > max_xor) {
            max_xor = curr_xor;
            buffer[0] = curr_xor ^ nums[i];
            buffer[1] = nums[i];
        }
    }
    return max_xor;
}


int main()
{
    Trie trie;
    vector<int> nums1{1, 2, 3, 4};

    vector<uint32_t> buffer;
    int max_xor = max_xor_of_two(nums1, buffer);

    cout << "Maximum xor: " << max_xor << " = " << buffer[0] << " XOR " << buffer[1] << endl;

    return 0;
}
