/**
 * 48 最长不含重复字符的子字符串
 * https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> loc;
        int i_left = 0;
        int n_max = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (loc.find(s[i]) != loc.end() && loc[s[i]] >= i_left) {
                i_left = loc[s[i]] + 1;
            }
            if (i - i_left + 1 > n_max)
                n_max = i - i_left + 1;
            loc[s[i]] = i;
        }
        return n_max;
    }
};