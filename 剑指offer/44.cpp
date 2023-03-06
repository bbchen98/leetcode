/**
 * 44 数字序列中某一位的数字
 * https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
 */

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)
            return n;
        n -= 10;
        long long base = 90;
        int bit = 2;
        while (n >= base * bit) {
            n -= base * bit;
            base *= 10;
            ++bit;
        }

        int target_n = base / 9 + n / bit;
        n = n % bit;
        int ans = to_string(target_n)[n] - '0';
        return ans;
    }
};