/**
 * 54 二叉搜索树的第k大节点
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
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

    void midUnorder(TreeNode* root, int& k, int& ans) {
        if (root == nullptr) return;
        midUnorder(root->right, k, ans);
        --k;
        if (k == 0)
            ans = root->val;
        midUnorder(root->left, k, ans);
    }

    int kthLargest(TreeNode* root, int k) {
        int ans = root->val;
        midUnorder(root, k, ans);
        return ans;
    }
};