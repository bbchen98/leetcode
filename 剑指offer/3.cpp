/*
 * 03 数组中重复的数字
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
    int findRepeatNumber2(vector<int>& nums) {
        int n = nums.size(), i = 0, t = 0;
        while (i < n) {
            if (nums[i] == i)
                ++i;
            else if (nums[i] == nums[nums[i]])
                return nums[i];
            else {
                t = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = t;
            }
        }
        return 0;
    }
};