class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto& str : strs) {
		
		std::vector<int> chars(26, 0);
		for (int i = 0; i < str.size(); ++i) {
			chars[str[i] - 'a']++;
		}

		std::string key(chars.begin(), chars.end());

		groups[key].push_back(str);

    }

	std::vector<std::vector<std::string>> result;
	for (const auto& [_, value] : groups) {
		result.push_back(value);
	}

	return result;  
    }
};
