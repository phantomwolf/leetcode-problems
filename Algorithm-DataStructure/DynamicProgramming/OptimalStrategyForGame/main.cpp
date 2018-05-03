#include <iostream>
#include <vector>

using namespace std;


int solution(const vector<int> &coins)
{
    int len = coins.size();
    int d[len][len];
    
// base cases
    // If there's only 1 coin available
    for (int i = 0; i < len; ++i) {
        d[i][i] = coins[i];
    }
    // If there're 2 coins available
    for (int i = 0; i < len - 1; ++i) {
        if (coins[i] > coins[i + 1]) {
            d[i][i + 1] = coins[i];
        } else {
            d[i][i + 1] = coins[i + 1];
        }
    }
    
    for (int n = 3; n <= len; ++n) {
        for (int i = 0; i + n <= len; ++i) {
            int j = i + n - 1;
            int cand1 = coins[i] + min(d[i+2][j], d[i+1][j-1]);
            int cand2 = coins[j] + min(d[i+1][j-1], d[i][j-2]);
            if (cand1 > cand2) {
                d[i][j] = cand1;
            } else {
                d[i][j] = cand2;
            }
        }
    }
    return d[0][len - 1];
}


int main(int argc, char *argv[])
{
    vector<int> coins{8, 15, 3, 7};
    int res = solution(coins);
    cout << "result: " << res << endl;

    return 0;
}
