// you can use includes, for example:
// #include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    double min = INT_MAX;
    int pos = -1;
    
    int *sum = new int[A.size() + 1];
    sum[0] = 0;
    for (unsigned int i = 0; i < A.size(); ++i)
        sum[i + 1] = sum[i] + A[i];
        
    // slices with length 2 and 3
    for (int len = 2; len <= 3; ++len) {
        for (unsigned int i = 0; i + len <= A.size(); ++i) {
            double avg = (sum[i + len] - sum[i]) / (double)len;
            if (avg < min) {
                min = avg;
                pos = i;
            }
        }
    }
    
    delete[] sum;
    return pos;
}
