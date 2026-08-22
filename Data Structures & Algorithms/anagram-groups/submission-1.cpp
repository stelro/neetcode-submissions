class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> freq;
	for (const auto& s : strs) {
		std::vector<char> count (26,0);
		for (const auto& c : s) {
			count[c - 'a']++;
		}

		std::string key = std::to_string(count[0]);
		for (int i = 1; i < 26; i++) {
			key += ',' + std::to_string(count[i]);
		}

		freq[key].push_back(s);
	}

	std::vector<std::vector<std::string>> result;
	for (const auto& [key, value] : freq) {
		result.push_back(value);
	}
		
	return result;
    }
};
