#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int max_chain_length(vector<pair<int, int>> &pairs)
{
    int len = pairs.size();
    // d[i]: longest length of chain if pairs[i-1] is in the chain
    int d[len];
    int s[len];

    d[0] = 1;
    s[0] = -1;
    for (int i = 1; i < len; ++i) {
        d[i] = 1;
        s[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (pairs[j].second < pairs[i].first && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                s[i] = j;
            }
        }
    }

    for (int i = 0; i < len; ++i) {
        printf("d[%d]: %d, s[%d]: %d\n", i, d[i], i, s[i]);
    }
    return d[len - 1];
}


int main(int argc, char *argv[])
{
    vector<pair<int, int>> pairs{{5, 24}, {15, 25},
                                 {27, 40}, {50, 60}};

    int res = max_chain_length(pairs);
    cout << "Length of maximum size chain is: " << res << endl;

    return 0;
}
