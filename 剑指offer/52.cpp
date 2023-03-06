/**
 * 52 两个链表的第一个公共节点
 * https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *t = headA;
        while (t != nullptr) {
            ++n1;
            t = t->next;
        }
        t = headB;
        while (t != nullptr) {
            ++n2;
            t = t->next;
        }
        ListNode * pa = headA;
        ListNode * pb = headB;
        if (n1 > n2) {
            while (n1 - n2 > 0) {
                pa = pa->next;
                --n1;
            }
        } else {
            while (n2 - n1 > 0) {
                pb = pb->next;
                --n2;
            }
        }
        while (pa != nullptr) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
};