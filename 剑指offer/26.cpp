/**
 * 26 树的子结构
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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

// 版本1：先序遍历，如果原始树的节点与目标树的根节点val相同，开始比较
class Solution {
public:

    bool compareNode(TreeNode* origin_tree, TreeNode* target_tree) {
        if (target_tree == nullptr) return true;
        if (origin_tree == nullptr || origin_tree->val != target_tree->val)
            return false;
        return compareNode(origin_tree->left, target_tree->left) &&
               compareNode(origin_tree->right, target_tree->right);
    }

    bool preOrder(TreeNode* tree, TreeNode* target_node) {
        if (tree == nullptr) return false;
        return compareNode(tree, target_node) || preOrder(tree->left, target_node) || preOrder(tree->right, target_node);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return false;
        return preOrder(A, B);
    }
};

// 版本2：将先序访问与原函数合并
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

    bool compareNode(TreeNode* origin_tree, TreeNode* target_tree) {
        if (target_tree == nullptr) return true;
        if (origin_tree == nullptr || origin_tree->val != target_tree->val)
            return false;
        return compareNode(origin_tree->left, target_tree->left) &&
               compareNode(origin_tree->right, target_tree->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        return compareNode(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};