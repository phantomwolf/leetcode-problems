#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Stores words that are already visited
    unordered_set<string> visited;
    // pair: (word, distance)
    queue<pair<string, int>> q;
    // Insert beginWord into queue
    q.push({beginWord, 1});
    visited.insert(beginWord);
    while (!q.empty()) {
      pair<string, int> p = std::move(q.front());
      q.pop();
      // Visit its neighbors
      for (string& w : wordList) {
        if (visited.contains(w)) {
          continue;
        }
        if (adjacent(p.first, w)) {
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

 private:
  bool adjacent(const string& word1, const string& word2) {
    int res = 0;
    for (int i = 0; i < word1.size(); i++) {
      if (word1[i] != word2[i]) {
        res++;
      }
    }
    return res == 1;
  }
};