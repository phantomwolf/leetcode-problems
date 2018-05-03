#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> next_greater_elements(vector<int> &nums)
{
    vector<int> res(nums.size());
    stack<int> st;
    st.push(0);

    for (size_t i = 1; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        res[st.top()] = -1;
        st.pop();
    } 
    return std::move(res);
}

int main(int argc, char *argv[])
{
    vector<int> nums{4, 5, 2, 25};
    vector<int> res;
    res = std::move(next_greater_elements(nums));
    for (size_t i = 0; i < res.size(); ++i) {
        cout << nums[i] << " => " << res[i] << endl;
    }

    return 0;
}
