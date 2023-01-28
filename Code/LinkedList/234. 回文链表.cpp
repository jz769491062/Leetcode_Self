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
// https://leetcode.cn/problems/palindrome-linked-list/description/
// 这次让我们利用后序遍历更聪明的解决这题
void traverse(ListNode head) {
    // 前序遍历代码
    traverse(head.next);
    // 后序遍历代码
}
class Solution {
public:
ListNode* left = NULL;
// 利用后序，模拟双指针
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }

    bool traverse(ListNode* right) {
        if (!right) return true; // 到了结尾，接下来看数值，所以这里return true
        bool res = traverse(right->next); // 让res继承之前的结果
        res = res && (right->val == left->val); // 每一个递归栈相当于right指针从右到左遍历
        left = left->next; // 判断完成，那么left也要向右走一个了
        return res;
    }
};

// 另一个优化空间复杂度的办法：用快满指针找到中点，反转中点之后的元素，然后left right双指针比较
// Java
boolean isPalindrome(ListNode head) {
    ListNode slow, fast;
    slow = fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    
    if (fast != null) // 快指针不为空，说明指针size是奇数，slow应该继续前进一格
        slow = slow.next;
    
    ListNode left = head;
    ListNode right = reverse(slow);
    while (right != null) {
        if (left.val != right.val)
            return false;
        left = left.next;
        right = right.next;
    }
    
    return true;
}

ListNode reverse(ListNode head) {
    ListNode pre = null, cur = head;
    while (cur != null) {
        ListNode next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}


// 一个简单思路是把链表倒着copy到一个新的链表，然后两链表遍历比较数值。是copy不是原地
class Solution {
public:
ListNode* curr = NULL;
    // 注意，要复制一条链表。原地操作的话head就乱了
    void getReverse(ListNode* head, ListNode* newHead) {
        if (!head || !head->next) {
            curr = newHead;
            curr->next = head;
            curr = curr->next;
            return;
        }
        getReverse(head->next, newHead);
        curr->next = new ListNode(head->val);
        curr->next->next = NULL;
        curr = curr->next;
        return;
    }

    bool isPalindrome(ListNode* head) {
        ListNode*h = head;
        ListNode* rev = new ListNode(-1);
        rev->next = NULL;
        getReverse(head, rev);
        rev = rev->next;
        while (rev) {
            if (rev->val != h->val) return false;
            rev = rev->next;
            h = h->next;
        }
        return true;
    };
};