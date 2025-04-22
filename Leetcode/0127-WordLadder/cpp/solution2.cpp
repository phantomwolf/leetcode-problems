#include <algorithm>
#include <string>
#include <unordered_map>

/*
Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"] Output: 5

dict: {
    *ot => [hot, dot, lot], h*t => [hot], ho* => [hot],
    d*t => [dot], do* => [dot, dog],
    *og => [dog, log, cog], d*g => [dog],
    l*t => [lot], lo* => [lot, log],
    l*g => [log],
    c*g => [cog], co* => [cog],
}

q = [{hit, 1}], visited = {hit}
maskedWord = *it|h*t|hi*, q = [{hot, 2}]
maskedWord = *ot|ho* q = [{dot, 3}, {lot, 3}]
maskedWord = d*t|do*|l*t|lo*, q = [{}]
*/
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int length = beginWord.size();
    // Preprocessing
    unordered_map<string, vector<string>> dict;
    for (const string& w : wordList) {
      for (int i = 0; i < length; i++) {
        string maskedWord = w.substr(0, i) + "*" + w.substr(i + 1, length);
        dict[maskedWord].push_back(w);
      }
    }
    // BFS
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    visited.insert(beginWord);
    while (!q.empty()) {
      pair<string, int> p = std::move(q.front());
      q.pop();
      // Visit its neighbors
      for (int i = 0; i < length; i++) {
        string maskedWord =
            p.first.substr(0, i) + "*" + p.first.substr(i + 1, length);
        for (string& w : dict[maskedWord]) {
          if (visited.contains(w)) {
            continue;
          }
          // Check if we've reached endWord
          if (w == endWord) {
            return p.second + 1;
          }
          q.push({w, p.second + 1});
          visited.insert(w);
        }
      }
    }
    return 0;
  }
};