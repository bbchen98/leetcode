/**
 * 7 重建二叉树
 * https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/
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
private:
    map<int, int> mp;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_s, int pre_e, int in_s, int in_e) {
        if (pre_s > pre_e || in_s > in_e)
            return nullptr;
        TreeNode *p = new TreeNode(preorder[pre_s]);
        int idx = mp[preorder[pre_s]];
        int n_left_tree = idx - in_s;
        p->left = build(preorder, inorder, pre_s + 1, pre_s + n_left_tree, in_s, idx - 1);
        p->right = build(preorder, inorder, pre_s + n_left_tree + 1, pre_e, idx + 1, in_e);
        return p;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};