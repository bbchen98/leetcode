/**
 * 219 打家劫舍 II
 * https://leetcode.cn/problems/house-robber-ii/
 */

class Solution {
public:

    int robAux(vector<int>& nums, int i_start, int i_end) {
        int n = i_end - i_start + 1;
        vector<int> dp(n, 0);
        dp[0] = nums[i_start];
        if (n == 1)
            return nums[i_start];
        dp[1] = max(nums[i_start], nums[i_start + 1]);
        for (int i = 2; i_start + i <= i_end; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i_start + i]);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int r1 = robAux(nums, 0, n - 2);
        int r2 = robAux(nums, 1, n - 1);
        return max(r1, r2);
    }
};