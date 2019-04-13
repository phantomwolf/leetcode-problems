#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>  ab_sum;
        for(auto a : A) {
            for(auto b : B) {
                ++ab_sum[a+b];
            }
        }

        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = ab_sum.find(0 - c - d);
                if(it != ab_sum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> A{0, 1, -1};
    vector<int> B{-1, 1, 0};
    vector<int> C{0, 0, 1};
    vector<int> D{-1, 1, 1};

    Solution s;
    int count = s.fourSumCount(A, B, C, D);
    cout << "result: " << count << endl;

    return 0;
}
