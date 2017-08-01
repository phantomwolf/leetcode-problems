#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

// pair: weight, value
int knapsack(int capacity, vector<pair<int, int>> &wv)
{
    const int len = wv.size();
    int d[len + 1][capacity + 1];
    memset(d, 0, (len + 1) * (capacity + 1) * sizeof(int));

    for (int i = 1; i <= len; ++i) {
        for (int j = 1;j <= capacity; ++j) {
            if (j < wv[i].first)
                d[i][j] = d[i - 1][j];
            else
                d[i][j] = max(d[i - 1][j], wv[i].second + d[i - 1][j - wv[i].first]);
        }
    }

    return d[len][capacity];
}


int main()
{
    int capacity = 50;
    vector<pair<int, int>> wv = {{10, 60}, {20, 100}, {30, 120}};

    int res = knapsack(capacity, wv);
    cout << "result: " << res << endl;

    return 0;
}
