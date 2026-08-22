class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> dups;
        for (auto n : nums) {
            if (dups.count(n)) return true;
            dups.insert(n);
        }
        return false;
    }
};