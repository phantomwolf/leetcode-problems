#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int length = A.size();
    unordered_map<int, int> mp;
    // Find the majority element
    // and count occurances of all elements in one loop
    int majority;
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (count == 0) {
            majority = A[i];
            count++;
        } else if (majority == A[i]) {
            count++;
        } else {
            count--;
        }
        mp[A[i]]++;
    }
    // find indexes
    int res = 0;
    int total_count = mp[majority];
    int curr_count = 0;
    for (int i = 0; i < length; ++i) {
        if (A[i] == majority) {
            curr_count++;
        }
        if (2 * curr_count > i + 1 &&
            2 * (total_count - curr_count) > length - i - 1) {
            res++;
        }
    }
    return res;
}
