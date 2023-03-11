/**
 * 42 接雨水
 * https://leetcode.cn/problems/trapping-rain-water/description/
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int h_left = 0;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && height[i] > height[dq.back()]) {
                int curr = dq.back();
                dq.pop_back();
                if (!dq.empty()) {
                    ans += (i - dq.back() - 1) * (min(height[dq.back()], height[i]) - height[curr]);
                }
            }
            dq.push_back(i);
        }
        return ans;
    }
};