#include <deque>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


void print_deque(const deque<pair<int, int>> &q, const string &msg)
{
    deque<pair<int, int>>::const_iterator iter = q.begin();
    cout << msg << ": [ ";
    while (iter != q.end()) {
        cout << "(" << iter->first << ", " << iter->second << ") ";
        ++iter;
    }
    cout << "]" << endl;
}


// 广度优先搜索
class Solution1
{
public:
    bool canCross(vector<int>& stones)
    {
        if (stones.size() == 2) {
            if (stones[1] == 1)
                return true;
            return false;
        }

        unordered_set<int> set;
        for (int i = 0; i < stones.size(); ++i) {
            set.insert(stones[i]);
        }
        deque<pair<int, int>> queue;

        queue.push_back(pair<int, int>(stones[1], 1));
        while (!queue.empty()) {
            pair<int, int> step = std::move(queue.front());
            queue.pop_front();
            for (int pace = step.second - 1; pace <= step.second + 1; ++pace) {
                if (pace == 0)
                    continue;
                int next_pos = step.first + pace;
                if (next_pos == stones.back()) {
                    return true;
                }
                if (set.find(next_pos) != set.end()) {
                    queue.push_back(pair<int, int>(next_pos, pace));
                }
            }
        }
        return false;
    }
};


// 深度优先搜索(迭代版)
class Solution2
{
public:
    bool canCross(vector<int>& stones)
    {
        unordered_set<int> set;
        set.insert(0);
        for (int i = 1; i < stones.size(); ++i) {
            set.insert(stones[i]);
            // 见README.rst中的“优化技巧”
            if (stones[i] - stones[i-1] > i)
                return false;
        }

        deque<pair<int, int>> stack;
        stack.push_back(pair<int, int>(stones[0], 0));
        print_deque(stack, "begin");

        do {
        phase1:
            // advance as far as possible
            pair<int, int> step;
            while (true) {
                bool stop = true;
                step = stack.back();
                for (int i = step.second + 1; i > 0 && i >= step.second - 1; --i) {
                    int pos = step.first + i;
                    cout << "trying: " << pos << "," << i << endl;
                    if (set.find(pos) != set.end()) {
                        stack.push_back(pair<int, int>(pos, i));
                        print_deque(stack, "push1");
                        stop = false;
                        break;
                    }
                }
                if (stop)
                    break;
            }
        phase2:
            // Frog can no longer advance, check if it reached destination
            step = std::move(stack.back());
            if (step.first == stones.back())
                return true;
            stack.pop_back();
            print_deque(stack, "pop1");
            // Choose another path. If no, move back
            while (stack.size() != 1) {
                for (int i = step.second - 1; i > 0 && i >= stack.back().second - 1; --i) {
                    int pos = stack.back().first + i;
                    cout << "trying: " << pos << "," << i << endl;
                    if (set.find(pos) != set.end()) {
                        stack.push_back(pair<int, int>(pos, i));
                        print_deque(stack, "push2");
                        goto phase1;
                    }
                }
                step = std::move(stack.back());
                stack.pop_back();
                print_deque(stack, "pop2");
            }
        } while (stack.size() != 1);
        return false;
    }
};

// 深度优先搜索（递归版）
class Solution3
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
            return false;

        unordered_set<int> set;
        set.insert(0);
        for (int i = 1; i < stones.size(); ++i) {
            set.insert(stones[i]);
            if (stones[i] - stones[i-1] > i) {
                return false;
            }
        }

        return canReach(set, stones.back(), 1, 1);
    }

private:
    bool canReach(const unordered_set<int> &set, int dest, int pos, int k)
    {
        if (pos + k - 1 == dest || pos + k == dest || pos + k + 1 == dest)
            return true;
        if (set.find(pos + k + 1) != set.end()) {
            if (canReach(set, dest, pos + k + 1, k + 1))
                return true;
        }
        if (set.find(pos + k) != set.end()) {
            if (canReach(set, dest, pos + k, k))
                return true;
        }
        if (k != 1 && set.find(pos + k - 1) != set.end()) {
            if (canReach(set, dest, pos + k - 1, k - 1))
                return true;
        }
        return false;
    }
};

// 动态规划
class Solution4
{
public:
    bool canCross(vector<int>& stones)
    {
        unordered_set<int> *dp = new unordered_set<int>[stones.size()]();
        dp[0].insert(0);
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int gap = stones[i] - stones[j];
                if (dp[j].find(gap - 1) != dp[j].end() ||
                    dp[j].find(gap) != dp[j].end() ||
                    dp[j].find(gap + 1) != dp[j].end()) {
                    dp[i].insert(gap);
                }
            }
        }
        if (!dp[stones.size() - 1].empty()) {
            delete[] dp;
            return true;
        }
        delete[] dp;
        return false;
    }
};


int main(int argc, char *argv[])
{

    Solution2 s;
    //vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
    vector<int> stones{0,1,3,6,10,13,15,18};
    if (s.canCross(stones)) {
        cout << "Yes, we can" << endl;
    } else {
        cout << "No, we can't" << endl;
    }

    return 0;
}
