#include <iostream>


using namespace std;


int main() {
    int a[3][4] = {
        {0, 1, 2, 3},
        {2, 3, 4, 5},
        {4, 5, 6, 7},
    };
    for (auto &i : a) {
        for (auto &j : i) {
            cout << j << endl;
            j *= 2;
        }
    }
}
