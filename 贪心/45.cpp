/**
 * 45 跳跃游戏 II
 * https://leetcode.cn/problems/jump-game-ii/
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n_steps = 0;
        int cur_max_dist = 0;
        int pre_max_dist = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_max_dist = max(cur_max_dist, i + nums[i]);
            if (i == pre_max_dist) {
                ++n_steps;
                pre_max_dist = cur_max_dist;
            }
        }
        return n_steps;
    }
};