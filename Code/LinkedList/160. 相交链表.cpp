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
        //走完链表A走B，走完B走A，这样两者步数相同抵达相交点
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            // 不要用a->next，就用A，不然错过相交点
            if (a == NULL) a = headB;
            else a = a->next;
            if (b == NULL) b = headA;
            else b = b->next;
        }
        return a;
    }
};
//https://leetcode.cn/problems/intersection-of-two-linked-lists/