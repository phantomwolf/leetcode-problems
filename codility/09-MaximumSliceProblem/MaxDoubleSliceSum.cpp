#include <limits>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> left_sum(A.size());
    vector<int> right_sum(A.size());
    left_sum[0] = 0;
    right_sum[A.size() - 1] = 0;
    for (unsigned int i = 1; i < A.size(); ++i) {
        int j = A.size() - i - 1;
        left_sum[i] = max(left_sum[i - 1] + A[i], A[i]);
        right_sum[j] = max(right_sum[j + 1] + A[j], A[j]);
    }
    // find the maximum result
    int max_sum = numeric_limits<int>::min();
    for (unsigned int i = 1; i < A.size() - 1; ++i) {
        int curr_sum = left_sum[i] - 2 * A[i] + right_sum[i];
        if (max_sum < curr_sum)
            max_sum = curr_sum;
    }
    return max_sum;
}
