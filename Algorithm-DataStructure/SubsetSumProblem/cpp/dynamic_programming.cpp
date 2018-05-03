#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void print_subsets(int set[], int i, int sum, bool **d, vector<int> p)
{
    if (sum == 0) {
        for (int i = 0; i < p.size(); ++i) {
            cout << p[i] << ", ";
        }
        cout << endl;
        return;
    }
    if (i == 0)
        return;
    if (d[sum][i - 1]) {
        print_subsets(set, i - 1, sum, d, p);
    }
    int remain = sum - set[i - 1];
    if (remain >= 0 && d[remain][i - 1]) {
        p.push_back(set[i - 1]);
        print_subsets(set, i - 1, remain, d, p);
    }
}

bool is_subset_sum(int set[], int n, int sum)
{
    bool **d = new bool*[sum + 1];
    for (int i = 0; i <= sum; ++i) {
        d[i] = new bool[n + 1];
    }

    for (int j = 0; j <= n; ++j)
        d[0][j] = true;
    for (int i = 1; i <= sum; ++i)
        d[i][0] = false;

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= sum; ++i) {
            d[i][j] = d[i][j - 1];
            if (i >= set[j - 1])
                d[i][j] |= d[i - set[j - 1]][j - 1];
        }
    }

    // print all subsets
    vector<int> p;
    print_subsets(set, n, sum, d, p);

    bool res = d[sum][n];

    for (int i = 0; i <= sum; ++i) {
        delete[] d[i];
    }
    delete[] d;

    return res;
}

int main()
{
    //int set[] = {3, 34, 4, 12, 5, 2};
    //int sum = 9;
    //int set[] = {2, 3, 5, 6, 8, 10};
    //int sum = 10;
    int set[] = {1, 2, 3, 4, 5};
    int sum = 10;
    bool res = is_subset_sum(set, sizeof(set) / sizeof(int), sum);
    if (res)
        puts("Found a subset with given sum");
    else
        puts("No subset with given sum");

    return 0;
}
