/**
 * 17 打印从1到最大的n位数
 * https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
 */

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max_n = 9;
        while (n > 1) {
            max_n = max_n * 10 + 9;
            --n;
        }
        vector<int> ans;
        for (int i = 1; i <= max_n; ++i) {
            ans.push_back(i);
        }
        return ans;
    }
};