#include <iostream>
#include <string>
using namespace std;

void reverse_string(string &s, int l, int r)
{
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        ++l;
        --r;
    }
}

int main()
{
    string s = "abcdefgh";
    reverse_string(s, 0, 2);
    reverse_string(s, 3, s.size()-1);
    reverse_string(s, 0, s.size()-1);
    cout << s << endl;
    return 0;
}
