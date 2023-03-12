/**
 * 309 最佳买卖股票时机含冷冻期
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 * 三个状态：冷冻期，持有，不持有
 * 状态转移：
 *      持有 -> 冷冻期 （卖出）
 *      持有，冷冻期 -> 持有（继续持有，或冷冻期结束后买入）
 *      不持有，冷冻期 -> 不持有（继续不持有，或冷冻期过去）
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [冷冻期，持有，不持有]
        int n_states = 3;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n_states, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][1] + prices[i];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};