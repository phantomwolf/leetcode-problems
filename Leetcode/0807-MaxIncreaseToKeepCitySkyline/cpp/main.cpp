#include <vector>
using namespace std;


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax(grid.size(), 0);
        vector<int> colMax(grid[0].size(), 0);
        for (int i = 0; i < rowMax.size(); i++) {
            for (int j = 0; j < colMax.size(); j++) {
                if (grid[i][j] > rowMax[i])
                    rowMax[i] = grid[i][j];
                if (grid[i][j] > colMax[j])
                    colMax[j] = grid[i][j];
            }
        }
        int result = 0;
        for (int i = 0; i < rowMax.size(); i++) {
            for (int j = 0; j < colMax.size(); j++) {
                if (rowMax[i] < colMax[j]) {

                    result += rowMax[i] - grid[i][j];
                } else {
                    result += colMax[j] - grid[i][j];
                }
            }
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> grid{
        {3,0,8,4},
        {2,4,5,7},
        {9,2,6,3},
        {0,3,1,0},
    };
    int res = s.maxIncreaseKeepingSkyline(grid);
    cout << res << endl;
}
