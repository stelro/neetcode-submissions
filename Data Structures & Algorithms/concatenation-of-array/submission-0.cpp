class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() * 2;
        std::vector<int> result (n);
        for (int i = 0; i < n; i++) {
            result[i] = (nums[i % nums.size()]);
        }
        return result;
    }
};