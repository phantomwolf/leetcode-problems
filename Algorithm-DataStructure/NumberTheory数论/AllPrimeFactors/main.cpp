#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_factors(int n)
{
    vector<int> res;
    // 若n为偶数，先处理2
    while (n & 1 == 0) {
        res.push_back(2);
        n >>= 1;
    }
    int end = sqrt(n) + 1;
    for (int i = 3; i < end; i += 2) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    // 若n还大于2，说明n为质数
    if (n > 2)
        res.push_back(n);
    return res;
}


int main()
{
    vector<int> res;
    int n = 315;
    res = prime_factors(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
