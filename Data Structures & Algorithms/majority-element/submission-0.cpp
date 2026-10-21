class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> maj;
        for (int n : nums) {
            maj[n]++;
        }
        int majority = 0, max = 0;
        for (auto [k, v] : maj) {
            if (v > max) {
                max = v;
                majority = k;
            }
        }

        return majority;
    }
};