/**
 * 10-1 斐波那契数列，初始数组：{0, 1}
 * https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/
 * 10-2 青蛙跳台阶，初始数组：{1, 1}
 * https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 */

class Solution {
public:
    int fib(int n) {
        int ia[2] = {0, 1}, t = 0;
        if (n <= 1)
            return ia[n];
        for (int i = 2; i <= n; i++) {
            t = (ia[0] + ia[1]) % 1000000007;
            ia[0] = ia[1];
            ia[1] = t;
        }
        return ia[1];
    }
};
