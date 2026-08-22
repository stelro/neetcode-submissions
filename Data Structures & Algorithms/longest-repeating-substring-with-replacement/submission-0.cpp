class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> letters(26, 0);
        int left = 0; 
        int right = 0;
        int max_window_freq = 0;
        int best = 0;

        while (right < s.size()) {
            max_window_freq = std::max(max_window_freq, ++letters[s[right] - 'A']);

            while ((right - left + 1) - max_window_freq > k) {
                --letters[s[left] - 'A'];
                left++;
            }

            best = std::max(best, (right - left + 1));

            right++;
        }


        return best;
    }
};
