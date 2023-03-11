/**
 * 493 下一个更大元素 I
 * https://leetcode.cn/problems/next-greater-element-i/
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        map<int, int> loc;
        for (const auto x: nums2) {
            loc[x] = -1;
            for (int i = 0; i < nums1.size(); ++i) {
                if (nums1[i] == x) {
                    loc[x] = i;
                    break;
                }
            }
        }
        deque<int> dq;
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); ++i) {
            while (!dq.empty() && nums2[i] > dq.back()) {
                if (loc[dq.back()] != -1) {
                    ans[loc[dq.back()]] = nums2[i];
                }
                dq.pop_back();
            }
            dq.push_back(nums2[i]);
        }
        return ans;
    }
};