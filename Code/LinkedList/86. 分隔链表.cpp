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
    ListNode* partition(ListNode* head, int x) {
        // dummy节点和遍历用的复制节点是一起使用的
        ListNode* small = new ListNode(0);
        ListNode* p1 = small;
        ListNode* large = new ListNode(0);
        ListNode* p2 = large;
        while(head) {
            if (head->val >= x) {
                p2->next = head;
                p2 = p2->next;
            } else {
                p1->next = head;
                p1 = p1->next;
            }
            // 此处head->next依然指向顺序的下一个节点，要断掉否则链表结尾处会形成环
            // 重要！！！原地操作，所以需要断开原链表中的每个节点的 next 指针
            // 不断掉的话，大链表结尾5，小链表结尾2,5还连着2没有断掉，
            // 所以结果就成了一个环形链表，最后检测结果时无限循环报错。
            // 输入：head = [1,4,3,2,5,2], x = 3, 输出：[1,2,2,4,3,5] 成了1-2-2-4-3-5-2-4-3-5-2-4-3-5-2......
            ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
        p1->next = large->next;
        return small->next;
    }
};