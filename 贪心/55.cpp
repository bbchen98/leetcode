/**
 * 55 跳跃游戏
 * https://leetcode.cn/problems/jump-game/
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > target)
                break;
            target = max(target, i + nums[i]);
        }
        return target >= nums.size() - 1;
    }
};