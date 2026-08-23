class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);
        std::vector<std::vector<int>> result;

        // -4, -1, -1, 0, 1, 2
        for (int k = 0; k < (int)nums.size(); k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int left = k + 1;
            int right = (int)nums.size() - 1;

            while (left < right) {
                // if (left == right || left == k || k == right) {
                //   left++;
                //   right--;
                //   continue;
                // }

                int sum = nums[left] + nums[right] + nums[k];

                if (sum == 0) {
                    result.push_back({nums[left], nums[right], nums[k]});
                    right--;
                    left++;
                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return result;
    }
};
