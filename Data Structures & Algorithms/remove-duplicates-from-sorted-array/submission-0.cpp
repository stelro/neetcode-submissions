class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1, r = 1;
        while (r < nums.size()) {
            if (nums[r - 1] != nums[r]) {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};