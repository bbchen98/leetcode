/**
 * 57-1 和为s的两个数字
 * https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * 57-2 和为s的连续正数序列
 * https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i_left = 0, i_right = nums.size() - 1;
        while (i_left < i_right) {
            if (nums[i_left] + nums[i_right] == target) {
                break;
            } else if (nums[i_left] + nums[i_right] > target) {
                --i_right;
            } else {
                ++i_left;
            }
        }
        vector<int> ans = {nums[i_left], nums[i_right]};
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i_left = 1, i_right = 2;
        int n_sum = 3;
        int i_end = target / 2 + 1;
        while (i_left <= i_end && i_left < i_right) {
            if (n_sum == target) {
                int n = i_right - i_left + 1;
                vector<int> vt(n, 0);
                for (int i = 0; i < n; ++i) {
                    vt[i] = i + i_left;
                }
                ans.push_back(vt);
                n_sum -= i_left;
                ++i_left;
            } else if (n_sum < target) {
                ++i_right;
                n_sum += i_right;
            } else {
                n_sum -= i_left;
                ++i_left;
            }
        }
        return ans;
    }
};