/**
 * 27 二叉树的镜像
 * https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
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

    TreeNode* exchangeNode(TreeNode* node) {
        if (node == nullptr) return nullptr;
        TreeNode* pt = exchangeNode(node->right);
        node->right = exchangeNode(node->left);
        node->left = pt;
        return node;
    }


    TreeNode* mirrorTree(TreeNode* root) {
        return exchangeNode(root);
    }
};