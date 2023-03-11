/**
 * 503 下一个更大元素 II
 * https://leetcode.cn/problems/next-greater-element-ii/
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            while (!dq.empty() && nums[idx] > nums[dq.back()]) {
                ans[dq.back()] = nums[idx];
                dq.pop_back();
            }
            dq.push_back(idx);
        }
        return ans;
    }
};