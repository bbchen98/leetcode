/**
 * 718 最长重复子数组
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 */

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        int ans = 0;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (nums1[i] == nums2[j]) {
                    if (i - 1 >= 0 && j - 1 >= 0 && nums1[i - 1] == nums2[j - 1]){
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};