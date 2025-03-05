#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int result = 0;
    for (int x = 0; x < grid.size(); x++) {
      for (int y = 0; y < grid[0].size(); y++) {
        if (grid[x][y] != 0) {
          result = max(result, dfs(grid, x, y));
        }
      }
    }
    return result;
  }

 private:
  const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int dfs(vector<vector<int>>& grid, int x, int y) {
    int origGold = grid[x][y];
    // Mark as visited by setting to 0
    grid[x][y] = 0;
    // Visit neighbors
    int maxGold = 0;
    for (const vector<int>& d : dirs) {
      int m = x + d[0], n = y + d[1];
      if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() &&
          grid[m][n] != 0) {
        maxGold = max(maxGold, dfs(grid, m, n));
      }
    }
    // Remove from path
    grid[x][y] = origGold;
    return maxGold + origGold;
  }
};