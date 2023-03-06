/**
 * 23 链表中环的入口节点
 * https://leetcode.cn/problems/c32eOV/
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return head;

        ListNode *p1 = head;
        ListNode *p2 = head->next;

        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != nullptr)
                p2 = p2->next;
        }
        // 无环
        if (p2 == nullptr) return nullptr;
        // 有环，计算环的大小
        int n = 1;
        p1 = p2->next;
        while (p1 != p2) {
            ++n;
            p1 = p1->next;
        }
        // 双指针获取入口
        p1 = head;
        p2 = head;
        while (n > 0) {
            p2 = p2->next;
            --n;
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};