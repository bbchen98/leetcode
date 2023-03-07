/**
 * 60 n个骰子的点数
 * https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/
 */

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(2, vector<double>(n * 6 + 1, 0));
        int flag = 0;
        // 初始第一个骰子
        for (int i = 1; i <= 6; ++i) {
            dp[0][i] = 1. / 6;
        }
        // 从1到n递推
        for (int i = 1; i < n; ++i) {
            flag = 1 - flag;
            for (int j = i + 1; j <= i * 6; ++j)
                dp[flag][j] = 0.;
            for (int j = i; j <= i * 6; ++j) {
                for (int k = 1; k <= 6; ++k)
                    dp[flag][j + k] += dp[1 - flag][j] / 6;
            }
        }
        vector<double> ans;
        for (int i = n; i <= n * 6; ++i)
            ans.push_back(dp[flag][i]);
        return ans;
    }
};
