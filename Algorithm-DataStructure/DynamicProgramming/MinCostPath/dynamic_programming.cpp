#include <iostream>
#include <limits>
#include <vector>
#include <deque>

using namespace std;

void backtrace(const vector<vector<int>> &grid, char **s, int len1, int len2)
{
    deque<pair<char, int>> stack;
    int i = len1 - 1, j = len2 - 1;
    while (i != 0 || j != 0) {
        stack.push_back(pair<char, int>{s[i][j], grid[i][j]});
        if (s[i][j] == 'r')
            --i;
        else if (s[i][j] == 'd')
            --j;
        else {
            --i;
            --j;
        }
    }

    cout << grid[0][0];
    while (!stack.empty()) {
        if (stack.back().first == 'r')
            cout << " → ";
        else if (stack.back().first == 'd')
            cout << " ↓ ";
        else
            cout << " ↘ ";
        cout << stack.back().second;
        stack.pop_back();
    }
    cout << endl;
}

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int len1 = grid.size(), len2 = grid[0].size();
        int **d = new int*[len1];
        char **s = new char*[len1];
        for (int i = 0; i < len1; ++i) {
            d[i] = new int[len2];
            s[i] = new char[len2];
        }

        // init (0, 0)
        d[0][0] = grid[0][0];
        s[0][0] = ' ';
        // init first row
        for (int i = 1; i < len1; ++i) {
            d[i][0] = d[i - 1][0] + grid[i][0];
            s[i][0] = 'r';  // going right
        }
        // init first column
        for (int j = 1; j < len2; ++j) {
            d[0][j] = d[0][j - 1] + grid[0][j];
            s[0][j] = 'd';  // going down
        }

        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                int min = d[i - 1][j];
                s[i][j] = 'r';
                if (min > d[i][j - 1]) {
                    min = d[i][j - 1];
                    s[i][j] = 'd';
                }
                if (min > d[i - 1][j - 1]) {
                    min = d[i - 1][j - 1];
                    s[i][j] = '&';
                }
                d[i][j] = min + grid[i][j];
            }
        }

        int res = d[len1 - 1][len2 - 1];

        backtrace(grid, s, len1, len2);

        for (int i = 0; i < len1; ++i) {
            delete[] d[i];
            delete[] s[i];
        }
        delete[] d;
        delete[] s;

        return res;
    }
};


int main(int argc, char *argv[])
{
    vector<vector<int>> grid{{1, 4, 1}, {2, 8, 5}, {3, 2, 3}};

    Solution s;
    int res = s.minPathSum(grid);
    cout << "res: " << res << endl;
    return 0;
}
