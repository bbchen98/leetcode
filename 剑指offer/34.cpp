/**
 * 34 二叉树中和为某一值的路径
 * https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
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

    void preOrder(TreeNode* root, vector<int>& path, vector<vector<int>>& ans, int n_sum, int target) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        n_sum += root->val;
        if (root->left == nullptr && root->right == nullptr && n_sum == target)
            ans.push_back(vector<int>(path.cbegin(), path.cend()));
        preOrder(root->left, path, ans, n_sum, target);
        preOrder(root->right, path, ans, n_sum, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        preOrder(root, path, ans, 0, target);
        return ans;
    }
};