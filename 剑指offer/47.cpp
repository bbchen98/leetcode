/**
 * 47 礼物的最大价值
 * https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        vector<vector<int>> value(n_rows, vector<int>(n_cols, 0));

        int v = 0;
        for (int i = 0; i < n_rows; ++i) {
            v += grid[i][0];
            value[i][0] = v;
        }
        v = 0;
        for (int i = 0; i < n_cols; ++i) {
            v += grid[0][i];
            value[0][i] = v;
        }

        for (int i = 1; i < n_rows; ++i) {
            for (int j = 1; j < n_cols; ++j) {
                value[i][j] = max(value[i - 1][j], value[i][j - 1]) + grid[i][j];
            }
        }

        return value[n_rows - 1][n_cols - 1];
    }
};