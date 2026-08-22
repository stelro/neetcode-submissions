class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); k++) {

            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }

            int left = k + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[k] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back({nums[left], nums[k], nums[right]});
                    right--;
                    left++;
                    
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};
