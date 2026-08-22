class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
		return {};
	}

        std::string result;

        for (const auto& s : strs) {
            std::size_t len = s.size();
            result += '#' + std::to_string(len) + '#';
            result += s;
        }

        return result;
    }

    vector<string> decode(string str) {
       std::vector<std::string> result;
        for (std::size_t i = 1; i < str.size(); ++i) {
            int len_to_parse = 0;
            if (str[i-1] == '#') {
                std::string digit;
                while (std::isdigit(str[i]) && str[i] != '#') {
                    digit += str[i++];
                }
                i++; // consume the last '#'
                len_to_parse = std::stoi(digit); 
                std::string tmp;
                for (int j = 0; j < len_to_parse; j++) {
                    tmp += str[i + j];
                }
                result.push_back(tmp);
                i += len_to_parse;
            }
        }

        return result;
    }
};
