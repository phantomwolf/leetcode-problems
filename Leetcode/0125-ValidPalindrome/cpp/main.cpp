#include <string>

using std::string;

class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      // Ignore non-alphanumeric characters
      while (i < j && !isAlphanumeric(s[i])) {
        i++;
      }
      while (i < j && !isAlphanumeric(s[j])) {
        j--;
      }
      if (i >= j) {
        break;
      }
      char c1 = tolower(s[i]);
      char c2 = tolower(s[j]);
      if (c1 != c2) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

 private:
  bool isAlphanumeric(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9')) {
      return true;
    }
    return false;
  }
};