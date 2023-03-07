/**
 * 63 股票的最大利润
 * https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> right_max(n, 0);
        int n_max = prices[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            right_max[i] = n_max;
            n_max = max(n_max, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, right_max[i] - prices[i]);
        }
        return ans;
    }
};