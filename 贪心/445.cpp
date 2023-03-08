/**
 * 445 分发饼干
 * https://leetcode.cn/problems/assign-cookies/
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n_g = g.size();
        int n_s = s.size();
        int i_s = 0, i_g = 0;
        int ans = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        while (i_g < n_g) {
            while (i_s < n_s && s[i_s] < g[i_g])
                ++i_s;
            if (i_s < n_s && i_g < n_g && s[i_s] >= g[i_g]) {
                ++i_s;
                ++i_g;
                ++ans;
            } else {
                break;
            }
        }
        return ans;
    }
};