class Solution {
 public:
  int jump(vector<int>& nums) {
    int last = nums.size() - 1;
    // BFS
    queue<int> q;
    unordered_set<int> visited;
    int steps = 0;
    // Visit 0
    q.push(0);
    visited.insert(0);
    while (!q.empty()) {
      int size = q.size();
      // Visit nodes with the same distance
      while (size > 0) {
        int v = q.front();
        q.pop();

        if (v == last) {
          return steps;
        }

        for (int u = v + 1; u <= last && u <= v + nums[v]; u++) {
          if (visited.contains(u)) {
            continue;
          }
          visited.insert(u);
          q.push(u);
        }
        size--;
      }
      // Increment steps
      steps++;
    }
    return -1;
  }
};
/* Verification:
Input: nums = [2,3,1,1,4]
Output: 2

last = 4
q = [0], visited = {0}, steps = 0
size = 1
    v = 0, q = [], u in range [1, 2]
q = [1, 2], visite = {0, 1, 2}, steps = 1
size = 2
    v = 1, q = [2], u in range [2, 4]
    v =
*/