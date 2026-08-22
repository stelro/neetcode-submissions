class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int left = 1;
	int right = *std::max_element(piles.begin(), piles.end());
	int result = right;

	while (left <= right) {
		int k = left + (right - left) / 2;

		long long total_speed = 0;
		for (auto p : piles) {
			total_speed += std::ceil(static_cast<double>(p) / k);
		}

		if (total_speed <= h) {
			result = k;
			right = k - 1;
		} else {
			left = k + 1;
		}
	}

	return result;
    }
};
