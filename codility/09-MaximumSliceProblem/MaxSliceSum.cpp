int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_sum = A[0];
    int curr_sum = A[0];
    for (unsigned int i = 1; i < A.size(); ++i) {
        curr_sum = max(curr_sum + A[i], A[i]);
        if (max_sum < curr_sum)
            max_sum = curr_sum;
    }
    return max_sum;
}
