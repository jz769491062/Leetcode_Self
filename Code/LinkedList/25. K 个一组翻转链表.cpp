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
    //先写一下反转节点a-b之间节点的函数,[a, b)
    ListNode* rev(ListNode* a, ListNode* b) {
        ListNode* prev = NULL;
        ListNode* curr = a;
        while (curr != b) {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case: null 或者大小不足k
        if (!head) return NULL;
        ListNode* a, *b;
        a = b = head;
        // 前进k步，获取b
        for (int i = 0; i < k; i++) {
            if (!b) return head;//不足k个，不反转，return head，等于是后面的都不反转直接顺延
            b = b->next;
        }
        ListNode* subResult = rev(a, b);
        a->next = reverseKGroup(b, k);// a->next接着下一组的newHead
        return subResult;
    }
};// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/