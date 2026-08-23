class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        for (int l = 0; l < nums1.size(); l++) {
            for (int r = 0; r < nums1.size() - 1; r++) {
                if (nums1[r] > nums1[r + 1]) {
                    std::swap(nums1[r + 1], nums1[r]);
                }
            }
        }
    }
};