/**
 * 24 反转链表
 * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *new_head = new ListNode(0, head);
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *pt = nullptr;
        // 反转
        while (cur != nullptr) {
            pt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pt;
        }
        // 将原先的头（现在的尾）next置空
        head->next = nullptr;
        // 返回现在的头（即pre）
        return pre;
    }
};