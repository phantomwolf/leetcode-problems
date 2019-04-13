#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp("(");
        dfs(res, tmp, n, 1, 0);
        return res;
    }

protected:
    void dfs(vector<string> &res, string tmp, int n, int l, int r) {
        if (tmp.size() == 2 * n) {
            res.push(std::move(tmp));
            return;
        }
        if (l != n) {
            dfs(res, tmp + '(', n, l + 1, r);
        }
        if (r < l) {
            dfs(res, tmp + ')', n, l, r + 1);
        }
    }
};
