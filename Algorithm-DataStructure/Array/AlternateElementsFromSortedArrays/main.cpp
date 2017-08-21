#include <iostream>
#include <vector>

using namespace std;


// When flag = 0, fetch from A; when 1, fetch from B.
// Fetch elements from A[i..A.size()-1] and B[j..B.size()-1]
void alternate_elements(vector<int> A, size_t i,
                        vector<int> B, size_t j,
                        char flag, vector<int> &arr,
                        vector<vector<int>> &res)
{
    if (flag == 0) {
        // Fetch element from A
        if (arr.empty()) {
            for (size_t k = i; k < A.size(); ++k) {
                vector<int> tmp(arr);
                tmp.push_back(A[k]);
                alternate_elements(A, k + 1, B, j, 1, tmp, res);
            }
            return;
        }
        for (size_t k = i; k < A.size(); ++k) {
            if (A[k] > arr.back()) {
                vector<int> tmp(arr);
                tmp.push_back(A[k]);
                alternate_elements(A, k + 1, B, j, 1, tmp, res);
            }
        }
        return;
    }
    // Fetch element from B
    for (size_t k = j; k < B.size(); ++k) {
        if (B[k] > arr.back()) {
            vector<int> tmp(arr);
            tmp.push_back(B[k]);
            res.push_back(tmp);
            if (k + 1 != B.size())
                alternate_elements(A, i, B, k + 1, 0, tmp, res);
        }
    }
}

int main()
{
    vector<int> A{10, 15, 25};
    vector<int> B{5, 20, 30};
    vector<int> arr;
    vector<vector<int>> res;

    alternate_elements(A, 0, B, 0, 0, arr, res);

    cout << "results: " << endl;
    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
