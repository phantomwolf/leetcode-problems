#include <iostream>
#include <vector>

using namespace std;


void union_intersection_of_sorted(const vector<int> &A,
                                  const vector<int> &B,
                                  vector<int> &U,   // union
                                  vector<int> &I)   // intersection
{
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            I.push_back(A[i]);
            U.push_back(A[i]);
            i++;
            j++;
        } else if (A[i] < B[j]) {
            U.push_back(A[i]);
            i++;
        } else {
            U.push_back(B[j]);
            j++;
        }
    }
    while (i < A.size()) {
        U.push_back(A[i]);
        i++;
    }
    while (j < B.size()) {
        U.push_back(B[j]);
        j++;
    }
}


int main()
{
    vector<int> A{1, 3, 4, 5, 7};
    vector<int> B{2, 3, 5, 6};
    vector<int> U;
    vector<int> I;
    union_intersection_of_sorted(A, B, U, I);
    cout << "A: ";
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ", ";
    }
    cout << endl << "B: ";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << ", ";
    }
    cout << endl << "Union: ";
    for (int i = 0; i < U.size(); ++i) {
        cout << U[i] << ", ";
    }
    cout << endl << "Intersection: ";
    for (int i = 0; i < I.size(); ++i) {
        cout << I[i] << ", ";
    }
    cout << endl;

    return 0;
}
