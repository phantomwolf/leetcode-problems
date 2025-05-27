#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (const string& str : strs) {
      string key(26, 0);
      for (char c : str) {
        key[c - 'a']++;
      }
      map[key].push_back(str);
    }

    vector<vector<string>> res;
    for (auto& [key, val] : map) {
      res.push_back(val);
    }
    return res;
  }
};
