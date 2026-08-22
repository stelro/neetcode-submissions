class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;
        int left = 0;
        int max_so_far = 0;
        int right = 0;

        for (; right < s.size(); right++) {

            char ch = s[right];
            freq[ch]++;
            
            max_so_far = std::max(max_so_far, freq[ch]);

            while (((right - left + 1) - max_so_far) > k) {
                freq[s[left]]--;
                left++;
            }

        }

        return (right - left);
    }
};
