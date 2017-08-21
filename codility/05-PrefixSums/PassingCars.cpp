#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int> &A) {
    int len = A.size();
    int count = 0;      // current amount of 0
    int res = 0;
    for (int i = 0; i < len; ++i) {
        if (A[i] == 1) {
            res += count;
            continue;
        }
        ++count;
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> A = {0, 1, 0, 1, 1};

    int res = solution(A);
    cout << "result: " << res << endl;

    return 0;
}
