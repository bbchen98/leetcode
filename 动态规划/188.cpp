/**
 * 188 买卖股票的最佳时机 IV
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        // [不操作，第一次买入，第一次卖出, ... , 第k次买入，第k次卖出]
        int n_states = 2 * k + 1;
        vector<vector<int>> dp(n, vector<int>(n_states, 0));
        for (int i = 1; i < n_states; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n_states - 1; j += 2) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
                ans = max(ans, max(dp[i][j], dp[i][j + 1]));
            }
        }
        return ans;
    }
};