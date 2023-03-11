/**
 * 343 整数拆分
 * https://leetcode.cn/problems/integer-break/
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            int n_max = 0;
            for (int j = 1; j <= i / 2; ++j) {
                n_max = max(n_max, j * max(i - j, dp[i - j]));
            }
            dp[i] = n_max;
        }
        return dp[n];
    }
};