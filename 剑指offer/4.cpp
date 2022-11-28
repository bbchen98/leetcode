/**
 * 4 二维数组中的查找
 * https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() or matrix[0].empty())
            return false;
        int n_rows = matrix.size(), n_cols = matrix[0].size();

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