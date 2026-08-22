class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         std::vector<int> prefix (nums.size(), 1);
        std::vector<int> postfix (nums.size(), 1);

        int pre_res = 1; 
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = pre_res;
            pre_res *= nums[i];
        }

        int post_res = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            postfix[i] = post_res;
            post_res *= nums[j];
        }

        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            nums[i] = prefix[i] * postfix[j];
        }

        return nums;
    }
};
