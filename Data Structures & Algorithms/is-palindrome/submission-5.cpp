class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            while (right > left && !std::isalnum(s[right])) {
                right--;
            }

            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
