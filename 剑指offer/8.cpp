/**
 * 8 二叉树的下一个节点
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

// 方法1：中序递归遍历，保存前一个节点指针
class Solution {
private:
    TreeNode* pre = nullptr;
public:
    TreeNode* nextNode(TreeNode* root, TreeNode* p) {
        if (!root)
            return nullptr;
        TreeNode *curr = nullptr;
        // left
        curr = nextNode(root->left, p);
        if (curr) return curr;
        // curr
        if (p == pre) return root;
        pre = root;
        // right
        curr = nextNode(root->right, p);
        if (curr) return curr;
        return nullptr;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return nextNode(root, p);
    }
};

// 方法2：中序栈遍历，保存前一个节点指针
class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *pre = nullptr, *curr = root;
        stack<TreeNode*> stk;
        while (!stk.empty() || curr) {
            // left
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            // curr
            curr = stk.top();
            stk.pop();
            if (pre == p) return curr;
            pre = curr;
            // right
            curr = curr->right;
        }
        return nullptr;
    }
};

// 方法3：分三种情况
class Solution3 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p)  return nullptr;
        TreeNode *ans = nullptr, *curr = p;
        // 有右子树，下一个节点为右子树的最左下角节点
        if (curr->right) {
            ans = curr->right;
            while (ans->left) {
                ans = ans->left;
            }
        } else {
            // 无右子树
            // 如果p为左节点，那么下一个节点是它的父节点
            // 如果p为右节点，不断往父节点回溯，直至出现一个左节点，它的父节点就是下一个节点。
            curr = root;
            while (curr) {
                if (curr->val > p->val) {
                    ans = curr;
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
