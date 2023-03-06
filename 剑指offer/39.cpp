/**
 * 39 数组中出现次数超过一半的数字
 * https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 1;
        int last = nums[0];
        for (auto e : nums) {
            if (e == last) {
                ++ct;
            } else {
                --ct;
                if (ct == 0) {
                    ct = 1;
                    last = e;
                }
            }
        }
        return last;
    }
};