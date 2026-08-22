class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord,
                 const std::vector<std::string> &wordList) {

  std::unordered_set<std::string> words(wordList.begin(), wordList.end());
  if (words.find(endWord) == words.end())
    return 0;

  std::queue<std::pair<std::string, int>> q; // word, steps
  q.push({beginWord, 1});

  while (!q.empty()) {
    auto [word, steps] = q.front();
    q.pop();

    if (word == endWord)
      return steps;

    for (int i = 0; i < word.size(); i++) {
      auto original = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        word[i] = c;

        if (words.find(word) != words.end()) {
          q.push({word, steps + 1});
          words.erase(word);
        }
      }

      word[i] = original;
    }
  }

  return 0;
}
};
