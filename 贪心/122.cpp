/**
 * 122 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 * 每天都操作，计算今天和昨天的差额，如果盈利，就真买，否则就不买。
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0)
                ans +=  prices[i] - prices[i - 1];
        }
        return ans;
    }
};