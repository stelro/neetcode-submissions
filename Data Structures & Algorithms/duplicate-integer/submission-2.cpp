class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> freq;
        for (auto n : nums) {
            if (freq.count(n)) {
                return true;
            }
            freq.insert(n);
        }
        return false;
    }
};