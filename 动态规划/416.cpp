/**
 * 416 分割等和子集
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return false;
        int n_sum = 0;
        for (const auto &x : nums)
            n_sum += x;
        if (n_sum % 2 != 0)
            return false;
        int bag_cap = n_sum / 2;
        vector<vector<int>> dp(n, vector<int>(bag_cap + 1, 0));
        for (int j = nums[0]; j <= bag_cap; ++j)
            dp[0][j] = nums[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= bag_cap; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = max(dp[i - 1][j - nums[i]] + nums[i], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][bag_cap] == bag_cap;
    }
};
