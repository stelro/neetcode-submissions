class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        int n = nums.size();
        std::vector<int> prefix(n);
        std::vector<int> postfix(n);
        prefix[0] = 1; 
        postfix[n-1] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i - 1];
        }

        for (int i = n - 2; i >=0; i--) {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = prefix[i] * postfix[i];
        }       

        return nums;
    }
};
