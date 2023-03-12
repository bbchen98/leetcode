/**
 * 219 打家劫舍 III
 * https://leetcode.cn/problems/house-robber-iii/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> robAux(TreeNode* root) {
        if (root == nullptr)
            return vector<int>{0, 0};
        // [偷，不偷]
        vector<int> n_left = robAux(root->left);
        vector<int> n_right = robAux(root->right);
        vector<int> rob_arr = {0, 0};
        rob_arr[0] = root->val + n_left[1] + n_right[1];
        rob_arr[1] = max(n_left[0], n_left[1]) + max(n_right[0], n_right[1]);
        return rob_arr;
    }

    int rob(TreeNode* root) {
        vector<int> arr = robAux(root);
        return max(arr[0], arr[1]);
    }
};