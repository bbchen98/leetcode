/**
 * 16 数值的整数次方
 * https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
 */

class Solution {
public:
    double myPow(double x, int n) {
        bool flag = n < 0;
        long nt = n;
        if (flag)   nt = -nt;
        double ans = 1, base = x;
        while (nt > 0) {
            if (nt & 0x1 == 1) {
                ans *= base;
            }
            base *= base;
            nt >>= 1;
        }
        return flag ? 1. / ans : ans;
    }
};