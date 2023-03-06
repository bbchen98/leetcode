/**
 * 21 调整数组顺序使奇数位于偶数前面
 * https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 */

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nums;

        int i_left = 0, i_right = n - 1;
        while (i_left < i_right) {
            // 寻找偶数
            while (i_left < i_right && nums[i_left] % 2 != 0) {
                ++i_left;
            }
            // 寻找奇数
            while (i_left < i_right && nums[i_right] % 2 != 1) {
                --i_right;
            }
            // 交换
            std::swap(nums[i_left], nums[i_right]);
        }
        return nums;
    }
};