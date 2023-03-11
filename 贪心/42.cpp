/**
 * 42 连续子数组的最大和
 * https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9;
        int n_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            n_sum += nums[i];
            ans = max(ans, n_sum);
            if (n_sum < 0) {
                n_sum = 0;
            }
        }
        return ans;
    }
};