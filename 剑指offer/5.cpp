/**
 * 5 替换空格
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 */


class Solution {
public:
    string replaceSpace(string s) {
        int n_space = count(s.cbegin(), s.cend(), ' ');
        int n_s = s.size();
        s.resize(s.size() + 2 * n_space);
        int i = n_s - 1, j = s.size() - 1;
        while (i < j){
            if (s[i] != ' ') {
                s[j--] = s[i];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            --i;
        }
        return s;
    }
};
