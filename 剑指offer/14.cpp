/**
 * 14-1 剪绳子
 * https://leetcode.cn/problems/jian-sheng-zi-lcof/
 */

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 2; i <= n; ++i) {
            int n_max = 0;
            for (int j = 1; j <= i / 2; ++j) {
                // max(i - j, dp[i - j]): 另一段是切，还是不切
                n_max = max(n_max, j * max(i - j, dp[i - j]));
            }
            dp[i] = n_max;
        }
        return dp[n];
    }
};
