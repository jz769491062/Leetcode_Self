/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;
        // 双指针。快指针先走n步
        // 如果快指针next是null,那么满指针next就是要删除的元素了
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // 特殊处理：fast为NULL，说明我们删除的是正数第一个节点
        if (fast == NULL) {
            return head->next;
        } else {
            slow->next = slow->next->next;
        }
        // 另一种方案：使用dummy节点，然后找倒数N+1个节点并删除，这样无需特殊处理
        return head;
    }
};
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/