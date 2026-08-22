class Solution {
public:
    string minWindow(string s, string t) {
		std::unordered_map<char, int> need_m;
	for (auto c : t) {
		need_m[c]++;
	}

	std::unordered_map<char, int> have_m;
	
	int need = need_m.size();
	int have = 0;
	int left = 0;

	int min_substr = std::numeric_limits<int>::max();
	int min_substr_index = -1;

	for (int right = 0; right < s.size(); right++) {
		char c = s[right];
		have_m[c]++;

		if (need_m.count(c) && have_m[c] == need_m[c]) {
			have++;
		}

		while (need == have) {
			if ((right - left + 1) < min_substr) {
				min_substr = right - left + 1;
				min_substr_index = left;
			}

			char d = s[left];
			have_m[d]--;

			if (need_m.count(d) && have_m[d] < need_m[d]) {
				have--;
			}
			left++;
		}
	}
	
	return (min_substr != std::numeric_limits<int>::max()) ? s.substr(min_substr_index, min_substr) : ""; 
    }
};
