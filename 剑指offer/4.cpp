/*
 * 4 二维数组中的查找
 */

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size();
        if (n_rows == 0)
            return false;
        int n_cols = matrix[0].size();

        int row = 0, col = n_cols - 1;
        while (row < n_rows && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                ++row;
            else
                --col;
        }
        return false;
    }
};