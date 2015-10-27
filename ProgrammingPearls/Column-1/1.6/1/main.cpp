#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

// Problem: If memory were not scarce, how would you implement a sort in a language with libraries for representing and soring sets

// cpp solution: use the ordered set in STL: set
void cpp_solution(int a[], int length)
{
    set<int> s;
    for (int i=0; i < length; ++i) {
        s.insert(a[i]);
    }
    // output nums
    set<int>::const_iterator iter = s.begin();
    cout << "cpp: ";
    while (iter != s.end()) {
        cout << *iter << ", ";
        ++iter;
    }
    cout << endl;
}

// c solution: qsort
int my_compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void c_solution(int a[], int length)
{
    qsort(a, length, sizeof(int), my_compare);
    cout << "c:   ";
    for (int i=0; i < length; ++i) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int a[] = {7, 1, 3, 9, 0, 5, 4};
    cpp_solution(a, 7);
    c_solution(a, 7);
    return 0;
}
