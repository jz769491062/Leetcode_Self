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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            if (fast->val != slow->val) {
                slow->next = fast;
                //注意先指向fast再推进slow，顺序
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 注意，断开与后面的连接
        slow->next = NULL;
        return head;
    }
};
//https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/