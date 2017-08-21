#include <iostream>

using namespace std;


int solution(int A, int B, int K) {
    int rem_A = A % K, rem_B = B % K;
    int begin = (rem_A == 0) ? A : (A - rem_A + K);
    int end = (rem_B == 0) ? B : (B - rem_B);
    if (begin > end)
        return 0;
    return (end - begin) / K + 1;
}
