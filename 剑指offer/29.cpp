/**
 * 29 顺时针打印矩阵
 * https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();

        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        int i_row = 0, i_col = 0;
        vector<int> ans;

        while (i_row * 2 < n_rows && i_col * 2 < n_cols) {
            int end_row = n_rows - 1 - i_row;
            int end_col = n_cols - 1 - i_col;

            // ->
            for(int i = i_col; i <= end_col; ++i) {
                ans.push_back(matrix[i_row][i]);
            }
            // down
            if (end_row - i_row > 0) {
                for (int i = i_row + 1; i <= end_row; ++i) {
                    ans.push_back(matrix[i][end_col]);
                }
            }
            // <-
            if (end_row - i_row > 0 && end_col - i_col > 0) {
                for (int i = end_col - 1; i >= i_col; --i) {
                    ans.push_back(matrix[end_row][i]);
                }
            }
            // up
            if (end_row - i_row > 0 && end_col - i_col > 0) {
                for (int i = end_row - 1; i > i_row; --i) {
                    ans.push_back(matrix[i][i_col]);
                }
            }

            ++i_row;
            ++i_col;
        }

        return ans;
    }
};