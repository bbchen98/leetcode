/**
 * 25 合并两个排序的链表
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* pt = ans;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                pt->next = l1;
                l1 = l1->next;
            } else {
                pt->next = l2;
                l2 = l2->next;
            }
            pt = pt->next;
        }
        if (l1 == nullptr) pt->next = l2;
        if (l2 == nullptr) pt->next = l1;

        return ans->next;
    }
};