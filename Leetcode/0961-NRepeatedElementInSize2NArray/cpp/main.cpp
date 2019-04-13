#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i=1; i < 3; i++) {
            for (int j=0; j < i; j++) {
                if (A[i] == A[j]) {
                    return A[i];
                }
            }
        }
        int buf[3] = {A[0], A[1], A[2]};
        for (int i = 3; i < A.size(); i++) {
            if (A[i] == buf[0])
                return buf[0];
            if (A[i] == buf[1])
                return buf[1];
            if (A[i] == buf[2])
                return buf[2];
            buf[0] = buf[1];
            buf[1] = buf[2];
            buf[2] = A[i];
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int num;
    //vector<int> A{1, 2, 3, 3};
    //vector<int> A{2,1,2,5,3,2};
    vector<int> A{2,6,2,1};
    num = s.repeatedNTimes(A);
    cout << "Result: " << num << endl;
    return 0;
}
