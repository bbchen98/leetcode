/**
 * 5 替换空格
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 */


class Solution {
public:
    string replaceSpace(string s) {
        // count for space
        int n_sp = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == ' ')
                ++n_sp;
        // resize
        int left = s.size() - 1;
        s.resize(s.size() + 2 * n_sp);
        int right = s.size() - 1;
        // move
        while (left >= 0) {
            if (s[left] == ' ') {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
            } else {
                s[right--] = s[left];
            }
            --left;
        }
        return s;
    }
};
