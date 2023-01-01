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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 如果result的head也是/依赖输入链表中的head，
        // 那我们需要dummy来进行指向，返回dummy->next
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                p->next = list2;
                list2 = list2->next;
            } else {
                p->next = list1;
                list1 = list1->next;
            }
            //p->next和list1/2都已经update完成，直接p=p->next即可，
            //不需要再创建temp然后更新一下p->next再推进p
            p = p->next;
        }
        // 如果链表大小不等，接上剩余的链表
        if (list1) {
            p->next = list1;
        } else if (list2) {
            p->next = list2;
        }
        return dummy->next;
    }
};
//https://leetcode.cn/problems/merge-two-sorted-lists/