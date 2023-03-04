/**
 * 12 矩阵中的路径
 * https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */
class Solution {
public:

    bool existAux(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i_row, int i_col, int w_idx) {
        if (board[i_row][i_col] != word[w_idx])
            return false;
        if (w_idx == word.size() - 1)
            return true;
        visited[i_row][i_col] = true;
        bool flag = false;
        vector<pair<int, int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (auto p : path) {
            int p0 = p.first + i_row, p1 = p.second + i_col;
            if (p0 >= 0 && p0 < board.size() && p1 >= 0 && p1 < board[0].size() && !visited[p0][p1]) {
                flag = flag || existAux(board, word, visited, p0, p1, w_idx + 1);
                if (flag) break;
            }
        }
        visited[i_row][i_col] = false;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        int n_rows = board.size(), n_cols = board[0].size();
        vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (board[i][j] == word[0] && existAux(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};