#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    int length = A.size();
    int count = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            for (int m = 0; m < length; m++) {
                for (int n = 0; n < length; n++) {
                    if (A[i] + B[j] + C[m] + D[n] == 0) {
                        count++;
                        cout << A[i] << " + " << B[j] << " + " << C[m] << " + " << D[n] << " = 0" << endl;
                    }
                }
            }
        }
    }
    return count;
}


int main()
{
    vector<int> A{0, 1, -1};
    vector<int> B{-1, 1, 0};
    vector<int> C{0, 0, 1};
    vector<int> D{-1, 1, 1};

    int count = fourSumCount(A, B, C, D);
    cout << "result: " << count << endl;

    return 0;
}
