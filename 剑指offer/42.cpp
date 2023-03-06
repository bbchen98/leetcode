/**
 * 42 连续子数组的最大和
 * https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (const auto &x : nums) {
            pre = max(x, pre + x);
            ans = max(pre, ans);
        }
        return ans;
    }
};