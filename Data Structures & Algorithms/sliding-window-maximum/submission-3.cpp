class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            
            int max = std::numeric_limits<int>::min();;
            for (int r = i; r < (i + k) && (i + k) <= n; r++) {
                //std::print("{} ", nums[r]);
                max = std::max(nums[r], max);
            }
            //std::println("");
            if (i + k > n) break;

            result.push_back(max);
        }

        return result;
    }
    
};
