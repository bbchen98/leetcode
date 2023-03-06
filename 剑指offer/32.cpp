/**
 * 32-1 从上到下打印二叉树
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 * 32-2 之字形打印二叉树
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ans;
        if (root == nullptr) return ans;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            TreeNode* curr = nullptr;
            while (n > 0) {
                curr = que.front();
                que.pop();
                ans.push_back(curr->val);
                if (curr->left != nullptr)
                    que.push(curr->left);
                if (curr->right != nullptr)
                    que.push(curr->right);
                --n;
            }
        }
        return ans;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        dq.push_back(root);

        bool to_right = true;

        while (!dq.empty()) {
            deque<int> curr_layer;
            TreeNode* curr_node = nullptr;
            int n = dq.size();
            while (n > 0) {
                curr_node = dq.front();
                dq.pop_front();
                // 放入全局的deque
                if (curr_node->left != nullptr)
                    dq.push_back(curr_node->left);
                if (curr_node->right != nullptr)
                    dq.push_back(curr_node->right);
                // 放入该层的deque
                if (to_right) {
                    curr_layer.push_back(curr_node->val);
                } else {
                    curr_layer.push_front(curr_node->val);
                }
                --n;
            }
            ans.push_back(vector<int>(curr_layer.begin(), curr_layer.end()));
            to_right = !to_right;
        }
        return ans;
    }
};