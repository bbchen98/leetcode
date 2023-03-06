/**
 * 55-1 二叉树的深度
 * https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/
 * 55-2 平衡二叉树
 * https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int n_left_tree = depth(root->left);
        int n_right_tree = depth(root->right);
        if (n_left_tree == -1 or n_right_tree == -1)
            return -1;
        if (abs(n_left_tree - n_right_tree) > 1)
            return -1;
        return max(n_left_tree, n_right_tree) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};