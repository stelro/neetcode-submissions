class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int total_profit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                total_profit = std::max(total_profit, profit);
            } else {
                left = right;
            }
            right++;
        }

        return total_profit;
        
    }
};
