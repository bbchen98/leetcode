/**
 * 49 丑数
 * https://leetcode.cn/problems/chou-shu-lcof/
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int n2 = 0, n3 = 0, n5 = 0;
        int x = 0;
        for (int i = 1; i < n; ++i) {
            n2 = dp[i2] * 2;
            n3 = dp[i3] * 3;
            n5 = dp[i5] * 5;
            dp[i] = min(n2, min(n3, n5));
            if (dp[i] == n2)
                ++i2;
            if (dp[i] == n3)
                ++i3;
            if (dp[i] == n5)
                ++i5;
        }
        return dp[n - 1];
    }
};