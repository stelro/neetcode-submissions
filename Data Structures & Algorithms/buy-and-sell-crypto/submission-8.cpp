class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = 0;

        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                profit = std::max(profit, prices[right] - prices[left]);
            }
            right++;
        }

        return profit;
    }
};
