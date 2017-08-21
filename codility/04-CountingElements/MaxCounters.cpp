#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &A)
{
    vector<int> res(N, 0);
    int m = 0;      // current maximum counter value
    int last = 0;   // last time we do "max counter" operation, the maximum counter value
    for (int op : A) {
        if (op == N + 1) {
            last = m;
            continue;
        }
        res[op - 1] = 1 + max(res[op - 1], last);
        m = max(m, res[op - 1]);
    }
    for (int &num : res) {
        if (last > num)
            num = last;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int N = 5;
    vector<int> A = {3, 4, 4, 6, 1, 4, 4};

    vector<int> res = solution(N, A);
    for (auto i : res) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
