#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void print_partition_recursive(const string &s, size_t start, vector<vector<bool>> &d, vector<string> &pal)
{
    if (start == s.size()) {
        for (size_t i = 0; i < pal.size(); ++i) {
            cout << '"' << pal[i] << '"' << ", ";
        }
        cout << endl;
        return;
    }
    for (size_t end = start; end < s.size(); ++end) {
        if (d[start][end]) {
            vector<string> tmp(pal);
            tmp.push_back(s.substr(start, end - start + 1));
            print_partition_recursive(s, end + 1, d, tmp);
        }
    }
}

void all_partitions_recursive(const string &s)
{
    vector<vector<bool>> d(s.size(), vector<bool>(s.size()));
    for (size_t i = 0; i < s.size(); ++i)
        d[i][i] = true;
    for (size_t i = 1; i < s.size(); ++i)
        d[i-1][i] = (s[i-1] == s[i]) ? true : false;
    for (size_t len = 3; len <= s.size(); ++len) {
        for (size_t i = 0, j = i + len - 1; j < s.size(); ++i, ++j) {
            if (s[i] == s[j] && d[i + 1][j - 1])
                d[i][j] = true;
            else
                d[i][j] = false;
        }
    }
    // recursively print all solutions
    vector<string> pal;
    print_partition_recursive(s, 0, d, pal);
}


int main(int argc, char *argv[])
{
    all_partitions_recursive("nitin");

    return 0;
}
