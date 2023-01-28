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
    ListNode* reverseList(ListNode* head) {
        //判断!head是避免链表一开始就是空的，递归中主要还是看head->next，到最后一个元素就return
        if (!head || !head->next) return head;
        // 在第一次递归中锁定last是最后一个元素，其余的递归last都一直是最后一个元素(5)
        ListNode* last = reverseList(head->next);
        /*不能用last->next = head, 因为last将是反转后链表的头，
        last->next改变了的话，本来是5->4该3了，结果就成了5->3了，之前迭代接上的就给断掉了
        last是恒定的，但head在不同递归中是变化的，所以用head->next->next与时俱进接链表 */
        // 把原来的next元素的next指向自己。head->next->next原来指向null（第一次递归一开始最后一个元素next就是null,
        // 后序的递归head->next->next是Null是因为head->next = NULL设置的。）
        head->next->next = head;
        head->next = NULL;// 自身作为反转后最后一个元素，自然next要指向null而不是曾经的正序下一个元素了
        return last;// last就是最后我们要返回的答案，反转后链表的开头

        //方法2：迭代
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // while (curr) {
        //     ListNode* n = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = n;
        // }
        // return prev;
    }
};
// https://leetcode.cn/problems/reverse-linked-list/description/