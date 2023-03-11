/**
 * 739 每日温度
 * https://leetcode.cn/problems/daily-temperatures/
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if (n == 0)
            return vector<int>();

        vector<int> ans(n, 0);
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            // 取出deque尾部元素
            while (!dq.empty() && temperatures[dq.back()] < temperatures[i]) {
                ans[dq.back()] = i - dq.back();
                dq.pop_back();
            }
            // 放入新元素
            dq.push_back(i);
        }
        return ans;
    }
};