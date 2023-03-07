/**
 * 59-1 滑动窗口的最大值
 * https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 * 59-2 队列的最大值
 * https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        if (nums.size() == 0)
            return ans;
        // 处理前k个数
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        // 逐个处理
        for (int i = k; i < nums.size(); ++i) {
            // 剔除所有dque尾部比当前值小的
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            // 剔除过期的deque头部元素
            if (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();
            // 放入新的元素下标
            dq.push_back(i);
            // deque头部元素即为当前窗口最大值
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};