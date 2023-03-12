/**
 * 122 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [持有，不持有]
        vector<int> dp{0, 0};
        dp[0] = -prices[0];
        dp[1] = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            int have = max(dp[1] - prices[i], dp[0]);
            int dont_have = max(dp[0] + prices[i], dp[1]);
            dp[0] = have;
            dp[1] = dont_have;
        }
        return dp[1];
    }
};