#include <iostream>
#include <cstddef>
#include <limits>

using namespace std;


int optimal_cost(int keys[], int freq[], size_t n)
{
    int sum[n + 1];
    int cost[n][n];

    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + freq[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cost[i][i] = freq[i];
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            int j = i + l - 1;
            int min_cost = numeric_limits<int>::max();
            for (int r = i; r <= j; ++r) {
                int left = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;
                int tmp = left + right + sum[j + 1] - sum[i - 2];
                if (tmp < min_cost)
                    min_cost = tmp;
            }
            cost[i][j] = min_cost;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cout << "cost[" << i << "][" << j << "]: " << cost[i][j] << endl;
        }
    }
    return cost[0][n - 1];
}


int main(int argc, char *argv[])
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    size_t n = sizeof(keys) / sizeof(int);

    int res = optimal_cost(keys, freq, n);
    cout << "Cost of optimal BST: " << res << endl;

    return 0;
}
