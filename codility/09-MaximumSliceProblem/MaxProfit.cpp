#include <limits>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() == 0)
        return 0;
    int max_profit = 0;
    int min = A[0];
    for (unsigned int i = 1; i < A.size(); ++i) {
        int curr_profit = A[i] - min;
        if (max_profit < curr_profit)
            max_profit = curr_profit;
        if (min > A[i])
            min = A[i];
    }
    return max_profit;
}
