/**
 * 6 从尾到头打印链表
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }
        vector<int> vt;
        while (stk.size() > 0) {
            vt.push_back(stk.top());
            stk.pop();
        }
        return vt;
    }
};