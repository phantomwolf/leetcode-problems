#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct Item {
    int id;
    bool start;
    int time;
};

class Solution {
public:
    void parse_log(const string &log, struct Item &item)
    {
        size_t pos;
        item.id = stoi(log, &pos);
        ++pos;
        if (log[pos] == 's') {
            item.start = true;
            pos += 6;
        } else {
            item.start = false;
            pos += 4;
        }
        item.time = stoi(log.substr(pos, log.size() - pos));
    }

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> times(n, 0);

        deque<pair<int, int>> stack;
        struct Item item;
        for (int i = 0; i < logs.size(); ++i) {
            parse_log(logs[i], item);
            if (item.start) {
                stack.push_back(pair<int, int>(item.id, item.time));
            } else {
                int delta = item.time - stack.back().second + 1;
                times[stack.back().first] += delta;
                stack.pop_back();

                deque<pair<int, int>>::iterator iter = stack.begin();
                while (iter != stack.end()) {
                    iter->second += delta;
                    ++iter;
                }
            }
        }
        return times;
    }
};

int main()
{
    Solution s;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> res = s.exclusiveTime(2, logs);

    for (int i = 0; i < res.size(); ++i) {
        cout << i << ": " << res[i] << endl;
    }

    return 0;
}
