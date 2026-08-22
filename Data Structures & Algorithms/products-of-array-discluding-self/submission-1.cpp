class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefix(n);
        std::vector<int> postfix(n);

        prefix[0] = 1;
        postfix[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            postfix[j] = nums[j + 1] * postfix[j + 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = prefix[i] * postfix[i];
        }

        return nums;
    }
};
