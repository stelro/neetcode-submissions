class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) return {};

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        
        std::vector<std::vector<int>> result;
        for (int i = 0; i < n - 2; i++) {

            if (nums[i] > 0) break; // since the array is sorted, if we found any number that is greater than 0, 
                                    // we know that the next numbers too will be greater than 0, so it's
                                    // impossible to have a result that is equal to 0.
            if (i > 0 && nums[i - 1] == nums[i]) continue; // prevent duplicates, e.g. if i - 1 is the same as i then we will 
                                                // have the same triplet

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    
                    result.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    while (left < right && nums[left - 1] == nums[left]) 
                        left++;
                }
            }
        }

        return result;
    }
    
};
