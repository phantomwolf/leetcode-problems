#include <cmath>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    double square = sqrt(N);
    int    border = square;
    int    count  = 0;
    for (int i = 1; i <= border; ++i) {
        if (N % i == 0)
            count += 2;
    }
    if (border == square)
        count -= 1;
    return count;
}
