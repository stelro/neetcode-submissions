class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for (int k = 0; k < nums.size(); k++) {

            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k-1]) continue;

            int left = k + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[k] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[k], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }

        return result;
    }
    
};
