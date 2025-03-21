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
            // 2 DP arrays: min and max
            vector<vector<int>> dpMin(m, vector<int>(n, 0));
            vector<vector<int>> dpMax(m, vector<int>(n, 0));
            // Base case
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int up = (i-1 >= 0) ? dpMin[i-1][j] : 0;
                    int left = (j-1 >= 0) ? dpMin[i][j-1] : 0;
                    dpMin[i][j] = min(up, left) + grid[i][j];
    
                    up = (i-1 >= 0) ? dpMax[i-1][j] : 0;
                    left = (j-1 >= 0) ? dpMax[i][j-1] : 0;
                    dpMax[i][j] = max(up, left) + grid[i][j];
                }
            }
            if (t >= dpMin[m-1][n-1] && t <= dpMax[m-1][n-1]) {
                return true;
            }
            return false;
        }
    };
    