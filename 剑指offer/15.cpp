/**
 * 15 二进制中1的个数
 * https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            n &= n - 1;
            n >>= 1;
            ++ans;
        }
        return ans;
    }
};