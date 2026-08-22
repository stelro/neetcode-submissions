class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
		return 0;
        }

        int profit = 0;

        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                profit = std::max(profit, (prices[right] - prices[left]));
            }
            right++;
        }

        return profit;
    }
};
