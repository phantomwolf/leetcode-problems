#include <iostream>
#include <limits>
#include <vector>

using namespace std;


int MatrixChainOrder(const vector<int> &matrix)
{
    const int len = matrix.size() - 1;
    int d[len][len];

    for (int i = 0; i < len; ++i) {
        d[i][i] = 0;
    }

    for (int l = 2; l <= len; ++l) {
        for (int i = 0; i + l - 1 < len; ++i) {
            int j = i + l - 1;
            int min = numeric_limits<int>::max();
            for (int p = i + 1; p <= j; ++p) {
                int tmp = d[i][p - 1] + d[p][j] + matrix[i] * matrix[p] * matrix[j+1];
                if (min > tmp)
                    min = tmp;
            }
            d[i][j] = min;
        }
    }

    return d[0][len - 1];
}

int main(int argc, char *argv[])
{
    //vector<int> matrix{10, 20, 30, 40, 30};
    //vector<int> matrix{40, 20, 30, 10, 30};
    vector<int> matrix{10, 20, 30};

    int res = MatrixChainOrder(matrix);
    cout << "result: " << res << endl;

    return 0;
}
