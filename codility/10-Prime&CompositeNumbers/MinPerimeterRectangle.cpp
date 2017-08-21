#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int n = sqrt(N);
    for (int i = n; i > 0; --i) {
        if (N % i == 0)
            return (i + N / i) * 2;
    }
    return -1;
}
