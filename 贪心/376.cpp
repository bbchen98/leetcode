/**
 * 376 摆动序列
 * https://leetcode.cn/problems/wiggle-subsequence/
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;
        int pre_diff = nums[1] - nums[0];
        int ans = pre_diff == 0 ? 1 : 2;
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((diff < 0 && pre_diff >= 0) || (diff > 0 && pre_diff <= 0)) {
                ++ans;
                pre_diff = diff;
            }

        }
        return ans;
    }
};