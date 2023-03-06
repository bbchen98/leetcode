/**
 * 50 第一个只出现一次的字符
 * https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/description/
 */

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> uomap;
        for (const char &c : s) {
            if (uomap.count(c) == 0) {
                uomap[c] = 1;
            } else
                ++uomap[c];
        }
        for (const char &c : s) {
            if (uomap[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};