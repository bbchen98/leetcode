/**
 * 45 把数组排成最小的数
 * https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 */

class Solution {
public:

    string minNumber(vector<int>& nums) {
        vector<string> sv;
        for (const auto &x : nums) {
            sv.push_back(to_string(x));
        }
        std::sort(sv.begin(), sv.end(),[](string &x, string &y) {return x + y < y + x;});
        string ans;
        for (const auto x : sv) {
            ans.append(x);
        }
        return ans;
    }
};