/**
 * 135 分发糖果
 * https://leetcode.cn/problems/candy/
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = max(candies[i], candies[i - 1] + 1);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        int ans = 0;
        for (const auto &x : candies) {
            ans += x;
        }
        return ans;
    }
};