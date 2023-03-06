/**
 * 33 二叉搜索树的后序遍历序列
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/description/
 */


class Solution {
public:

    bool check(vector<int>& postorder, int i_left, int i_right) {
        if (i_left >= i_right)
            return true;
        int idx = i_left;
        int i_range = 0;
        while (postorder[idx] < postorder[i_right])
            ++idx;
        i_range = idx - 1;
        while (postorder[idx] > postorder[i_right])
            ++idx;
        return idx == i_right && check(postorder, i_left, i_range) && check(postorder, i_range + 1, i_right - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return check(postorder, 0, postorder.size()-1);
    }
};