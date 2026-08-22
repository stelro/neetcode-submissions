class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (auto n : nums) {
            auto [_, inserted] = set.insert(n);
            if (!inserted) {
                return n;
            }
        }
        
        return 0;
    }
};
