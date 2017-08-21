#include <iostream>
#include <vector>
#include <string>


using namespace std;


vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int len = S.size();
    int *A = new int[len + 1];
    int *C = new int[len + 1];
    int *G = new int[len + 1];
    A[0] = C[0] = G[0] = 0;
    for (int i = 0; i < len; ++i) {
        switch(S[i]) {
        case 'A':
            A[i + 1] = A[i] + 1;
            C[i + 1] = C[i];
            G[i + 1] = G[i];
            break;
        case 'C':
            A[i + 1] = A[i];
            C[i + 1] = C[i] + 1;
            G[i + 1] = G[i];
            break;
        case 'G':
            A[i + 1] = A[i];
            C[i + 1] = C[i];
            G[i + 1] = G[i] + 1;
            break;
        default:
            A[i + 1] = A[i];
            C[i + 1] = C[i];
            G[i + 1] = G[i];
        }
    }
    
    vector<int> res(P.size());
    for (int i = 0; i < P.size(); ++i) {
        if (A[Q[i] + 1] - A[P[i]] != 0) {
            res[i] = 1;
        } else if (C[Q[i] + 1] - C[P[i]]) {
            res[i] = 2;
        } else if (G[Q[i] + 1] - G[P[i]]) {
            res[i] = 3;
        } else {
            res[i] = 4;
        }
    }
    
    delete[] A;
    delete[] C;
    delete[] G;
    return res;
}
