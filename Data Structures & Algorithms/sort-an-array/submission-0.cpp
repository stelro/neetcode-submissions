class Solution {
private:
    void merge(std::vector<int>& input, std::vector<int>& aux, 
        int left, int mid, int right) {
            if (left >= right) return;
            for (int k = left; k <= right; k++) {
                aux[k] = input[k];
            }
            int i = left; // the start of the left array
            int j = mid + 1; // the start of the right array
            for (int k = left; k <= right; k++) {
                if (i > mid) {
                    // if we finsihed with the left array, copy from right
                    input[k] = aux[j++];
                } else if (j > right) {
                    // if we finsihed with the right array, crom from left
                    input[k] = aux[i++];
                } else if (aux[j] < aux[i]) {
                    input[k] = aux[j++];
                } else {
                    input[k] = aux[i++];
                }
            }
    }

    void merge_sort(std::vector<int>& input, std::vector<int>& aux, 
        int left, int right) {
            if (left >= right) return;

            int mid = left + (right - left) / 2;
            merge_sort(input, aux, left, mid);
            merge_sort(input, aux, mid + 1, right);
            merge(input, aux, left, mid, right);
        }
public:
    vector<int> sortArray(vector<int>& nums) {
        std::vector<int> aux (nums.size());
        merge_sort(nums, aux, 0, nums.size() - 1);
        return nums;
    }
};