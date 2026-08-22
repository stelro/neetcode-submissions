class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        std::vector<int> prefix(n, 0);
        std::vector<int> suffix(n, 0);

        prefix[0] = height[0];
        suffix[n - 1] = height[n - 1];

        for (int i = 0; i < n - 1; i++) {
            prefix[i + 1] = std::max(prefix[i], height[i + 1]);
        }

        for (int i = n - 1; i > 0; i--) {
            suffix[i - 1] = std::max(suffix[i], height[i - 1]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += std::min(prefix[i], suffix[i]) - height[i];
        }
        return count;
    }
};
