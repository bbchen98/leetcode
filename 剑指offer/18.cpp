/**
 * 18 删除链表的节点
 * https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return head;

        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *pre = new_head;
        ListNode *cur = new_head->next;

        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                break;
            }
            pre = pre->next;
            cur = cur->next;
        }

        return new_head->next;
    }
};