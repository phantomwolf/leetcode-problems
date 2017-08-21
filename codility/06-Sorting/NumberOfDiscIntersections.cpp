#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int len = A.size();
    vector<int> upper(len);
    vector<int> lower(len);
    
    for (int i = 0; i < len; ++i) {
        upper[i] = i + A[i];
        lower[i] = i - A[i];
    }
    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());

    cout << "upper: ";
    for (int i = 0; i < len; ++i) {
	    cout << upper[i] << ", ";
    }
    cout << endl << "lower: ";
    for (int i = 0; i < len; ++i) {
	    cout << lower[i] << ", ";
    }
    cout << endl;

    int j = 0;
    int count = 0;
    for (int i = 0; i < len; ++i) {
        while (j < len && upper[i] >= lower[j]) {
            count += j - i;
	    cout << "i: " << i << ", j: " << j << ", count += " << j - i << endl;
            ++j;
        }
        if (count > 10000000)
            return -1;
    }
    return count;
}


int main(int argc, char *argv[])
{
    vector<int> A = {1, 5, 2, 1, 4, 0};
    int res = solution(A);
    cout << "result: " << res << endl;

    return 0;
}
