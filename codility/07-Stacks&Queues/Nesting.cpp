#include <string>

using namespace std;


int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int stack_size = 0;
    int length = S.size();
    for (int i = 0; i < length; ++i) {
        if (S[i] == '(') {
            stack_size++;
            continue;
        }
        if (stack_size == 0)
            return 0;
        stack_size--;
    }
    if (stack_size == 0)
        return 1;
    return 0;
}
