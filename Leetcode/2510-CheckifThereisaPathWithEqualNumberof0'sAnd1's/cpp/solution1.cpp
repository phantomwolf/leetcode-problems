#include <vector>

using namespace std;

// m+n-1 steps. its sum should be (m+n-1)/2
class Solution {
    public:
        bool isThereAPath(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            int t = (m+n-1)/2;
            if ((m+n-1) %2 != 0) {
                return false;
            }
            // dp[i][j][k]: if true, there's a path to (i,j) that sums up to k
            vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(t+1, 0)));
            // Base case
            dp[0][0][grid[0][0]] = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k <= t; k++) {
                        if (i == 0 && j == 0) {
                            break;
                        }
                        bool up = (i-1 >= 0 && k-grid[i][j] >= 0) ? dp[i-1][j][k-grid[i][j]] : false;
                        bool left = (j-1 >= 0 && k-grid[i][j] >= 0) ? dp[i][j-1][k-grid[i][j]] : false;
                        dp[i][j][k] = up || left;
                    }
                }
            }
            return dp[m-1][n-1][t];
        }
    };
/*
Verification:
    Input: grid = [
        [0,1,0,0],
        [0,1,0,0],
        [1,0,1,0]]
    
    In the parentheses, we have the sum of the path to that cell.
    dp = [
        [(0),   (1)        (1),     (1)]
        [(0),   (1,2)      (1,2)    (1,2)]
        [(1),   (1,2)      (2,3)    (1,2,3)]
    ]

    m = 3, n = 4, t = (3+4-1)/2 = 3
    dp[m-1][n-1][t] = dp[2][3][3] = true
*/