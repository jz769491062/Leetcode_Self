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
//只反转一部分，那我们需要记录一下尾部未反转部位在哪
// 反转整个链表的话，就好比后驱节点固定是NULL
ListNode* successor = NULL; 
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {//注意n==1就该停了，不然就错误扭转后驱节点本身了，那是区间+1的位置
            successor = head->next;// 找到了应得的后驱节点
            return head;//这里return的就是我们需要开始扭转的节点了，目前位于反转区间的最后一个
        }
        ListNode* last = reverseN(head->next, n - 1); // 注意，以head->next为起点，所以是n-1
        head->next->next = head;
        head->next = successor; // 和反转整个链表的区别：新尾巴接到后驱节点上
        return last; //return我们的结果，扭转前扭转区间内的最后一个节点
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 更简洁的解法：递归
        // 我们要保留头部不动部分的顺序，还要接受reverseN的结果，然后尾巴也要接上
        // 实质上只有left==1的时候才可以直接开始搞reverseN，那就通过递归前进到那个位置然后开始吧
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
        
        // 自己写的迭代方法，也能过，但怎么有点复杂，需要处理left=1的特殊case
        // ListNode* startPt = head;
        // ListNode* startPrev = NULL;
        // bool advanced = false;// 有推进过startPt指针吗？
        // while (left > 1) {
        //     startPrev = startPt;
        //     startPt = startPt->next;
        //     left--;
        //     right--;// 注意，left和right是个区间，所以left移动了，right也要跟着减，确保reverseN数量对
        //     advanced = true;
        // }
        // ListNode* res = reverseN(startPt, right);
        // if (advanced) {// 如果推进过，把reverseN结果接到prev的next
        //     startPrev->next = res;
        // } else {//没推进，直接就从头部开始反转的，所以头部就是res
        //     head = res;
        // }
        // return head;
    }
}; // https://leetcode.cn/problems/reverse-linked-list-ii/description/