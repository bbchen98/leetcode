/**
 * 22 链表中倒数第k个节点
 * https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p_left = head;
        ListNode *p_right = head;

        while ( k > 0 && p_right != nullptr) {
            p_right = p_right->next;
            --k;
        }

        while (p_right != nullptr) {
            p_right = p_right->next;
            p_left = p_left->next;
        }

        return p_left;
    }
};
