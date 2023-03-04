/**
 * 13 机器人的运动范围
 * https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 */
class Solution {
public:

    int getSum(int n) {
        int n_sum = 0;
        while (n > 0) {
            n_sum += n % 10;
            n /= 10;
        }
        return n_sum;
    }

    void movingCountAux(int m, int n, int i, int j, vector<vector<bool>>& visited, int k, int& ans) {
        if (getSum(i) + getSum(j) > k) return;
        ++ans;
        visited[i][j] = true;
        vector<pair<int, int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto p : path) {
            int newi = i + p.first, newj = j + p.second;
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && !visited[newi][newj]) {
                movingCountAux(m, n, newi, newj, visited, k, ans);
            }
        }
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        movingCountAux(m, n, 0, 0, visited, k, ans);
        return ans;
    }
};