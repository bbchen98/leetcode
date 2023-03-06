/**
 * 46 把数字翻译成字符串
 * https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 */

class Solution {
public:
    int translateNum(int num) {
        string sn = to_string(num);
        if (sn.size() < 2)
            return 1;
        vector<int> dp(sn.size(), 0);
        dp[0] = 1;
        dp[1] = std::stoi(sn.substr(0, 2)) > 25? 1 : 2;
        for (int i = 2; i < sn.size(); ++i) {
            if (std::stoi(sn.substr(i - 1, 2)) <= 25 && sn[i - 1] != '0') {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};