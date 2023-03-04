/**
 * 03 数组中重复的数字
 * https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */


class Solution {
public:
    // 方法1：set
    int findRepeatNumber(vector<int>& nums) {
        set<int> st;
        for (auto n : nums){
            if (st.find(n) == st.end()){
                st.insert(n);
            } else {
                return n;
            }
        }
        return 0;
    }
    // 方法2：排序
    // 分两种情况：当前元素需要移动，或不需要。如果需要，需判断和目的位置的元素是否相同，如果相同则为要找的元素，不相同就移动。
    int findRepeatNumber2(vector<int>& nums) {
        int idx = 0, end = nums.size(), t;
        for (int i = 0; i < nums.size(); ++i) {
            // no need to exchange
            if (nums[idx] == idx) {
                ++idx;
            } else {    // need to exchange
                if (nums[idx] == nums[nums[idx]])
                    return nums[idx];
                else {
                    t = nums[nums[idx]];
                    nums[nums[idx]] = nums[idx];
                    nums[idx] = t;
                }
            }
        }
        return nums[idx];
    }
    // 方法二变体：
    // 无非三种情况：当前处理的元素，要么对应的位置已经存放了正确的数字（题解），
    // 要么该元素已经放到了正确的位置（需处理下一个元素），要么需要交换到对应的位置
    int findRepeatNumber3(vector<int>& nums) {
        int idx = 0, end = nums.size();
        while (idx < end) {
            if (nums[idx] != idx && nums[idx] == nums[nums[idx]]) {
                return nums[idx];
            } else if (nums[idx] == idx) {
                ++idx;
            } else {
                std::swap(nums[idx], nums[nums[idx]]);
            }
        }
        return -1;
    }
};