/**
 * 674 最长连续递增序列
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int n_lst = 1;
        int ans = n_lst;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 0) {
                ++n_lst;
            } else {
                n_lst = 1;
            }
            ans = max(ans, n_lst);
        }
        return ans;
    }
};