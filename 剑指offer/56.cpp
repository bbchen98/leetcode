/**
 * 56-1 数组中只出现一次的两个数字
 * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 * 56-2 数组中唯一只出现一次的数字
 * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 */

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unsigned int n_xor = 0;
        for (const auto e : nums) {
            n_xor ^= e;
        }
        unsigned int bit_flag = 0x1;
        while ((n_xor & bit_flag) == 0)
            bit_flag <<= 1;

        int a = 0, b = 0;
        for (const auto e : nums) {
            if ((e & bit_flag) != 0)
                a ^= e;
            else
                b ^= e;
        }
        vector<int> ans = {a, b};
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit_arr(32, 0);
        for (const auto &x : nums) {
            unsigned int un = x & 0xffffffff;
            for (int i = 0; i < 32; ++i) {
                bit_arr[i] += un & 0x1;
                un >>= 1;
            }
        }
        unsigned int ans = 0;
        for (int i = 31; i >= 0; --i) {
            ans += bit_arr[i] % 3 == 0 ? 0 : 1;
            ans <<= 1;
        }
        ans >>= 1;
        return ans;
    }
};