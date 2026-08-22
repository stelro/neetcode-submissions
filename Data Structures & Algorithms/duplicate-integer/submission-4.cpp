class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> nums_set;
        for (int n : nums) {
            if (nums_set.contains(n)) return true;
            nums_set.insert(n);
        }
        return false;
    }
};