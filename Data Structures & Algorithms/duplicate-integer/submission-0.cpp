class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> elements;
        for (const auto& n : nums) {
            auto result = elements.insert(n);
            if (result.second == false) {
                return true;
            }
        }
        return false;
    }
};
