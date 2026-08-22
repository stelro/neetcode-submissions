class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      std::unordered_map<char, int> count1;
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            count1[s1[i]]++;
        }
        int need = count1.size();
        for (int i = 0; i < s2.size(); i++) {
            std::unordered_map<int, char> count2;
            int curr = 0;
            for (int j = i; j < s2.size(); j++) {
                char c = s2[j];
                count2[c]++;

                if (count1[c] < count2[c]) {
                    break;
                }
                
                if (count1[c] == count2[c]) {
                    curr++;
                }

                if (need == curr) {
                    return true;
                }
            }
        }

        return false;
    }
};
