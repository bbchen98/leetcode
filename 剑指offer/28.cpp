/**
 * 28 对称的二叉树
 * https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/
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

    bool compareNode(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr && tree2 == nullptr)
            return true;
        if (tree1 == nullptr && tree2 != nullptr)
            return false;
        if (tree1 != nullptr && tree2 == nullptr)
            return false;
        if (tree1->val != tree2->val)
            return false;
        return compareNode(tree1->left, tree2->right) && compareNode(tree1->right, tree2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compareNode(root->left, root->right) && compareNode(root->right, root->left);
    }
};