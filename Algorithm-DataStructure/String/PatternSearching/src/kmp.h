#ifndef _KMP_TABLE_
#define _KMP_TABLE_

#include <string>
#include <array>
using std::string;

void kmp_table(const string &s, const string &w, int t[]);

int kmp_search(const string &s, const string &w);


#endif
