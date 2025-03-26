#include <vector>

using namespace std;

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    visited[start] = true;
    return dfs(arr, start, visited);
  }

  bool dfs(vector<int>& arr, int index, vector<bool>& visited) {
    if (arr[index] == 0) {
      // reached element 0
      return true;
    }
    int size = arr.size();
    // Visit adjacent nodes
    int left = index - arr[index];
    if (left >= 0 && !visited[left]) {
      visited[left] = true;
      bool reached = dfs(arr, left, visited);
      if (reached) {
        return true;
      }
    }
    int right = index + arr[index];
    if (right < size && !visited[right]) {
      visited[right] = true;
      bool reached = dfs(arr, right, visited);
      if (reached) {
        return true;
      }
    }
    return false;
  }
};

/* Verification:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true

visit 5: left=4, right=6, visited={5}
    visit 4: left=1, visited={4,5}
        visit 1: right=3, visited={1,4,5}
            visit 3: found 0


Input: arr = [3,0,2,1,2], start = 2
Output: false

visit 2: left=0, right=4, visited={2}
    visit 0: right=3, visited={0,2}
        visit 3: left=2, right=4, visited={0,2,3}
            visit 4: left=2, visited={0,2,3,4}
    visit 4:
DFS done. Index 1 isn't visited. Return false.
*/