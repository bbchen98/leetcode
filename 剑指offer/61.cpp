/**
 * 61 扑克牌中的顺子
 * https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 */

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int n_jokers = 0;
        unordered_set<int> exist;
        int n_min = 14;
        int n_max = 0;
        for (const auto &x : nums) {
            if (x == 0)
                continue;
            if (exist.count(x) != 0)
                return false;
            exist.insert(x);
            n_min = min(n_min, x);
            n_max = max(n_max, x);
        }

        return n_max - n_min < 5;
    }
};