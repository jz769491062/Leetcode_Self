// https://leetcode.cn/problems/linked-list-random-node/description/
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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        // 怎么保证被选中结果每个相等呢？
        // 可以这么想：对于每个节点，有1/i几率选择这个节点，然后有1 - 1/i几率保持之前的选择。
        // 水塘抽样算法
        int i = 0, res = 0;
        ListNode* p = head;
        while (p) {
            i++;
            // rand() % i == 0 的概率就是1/i
            // 第一个节点概率1/i , 第二个节点概率 (1 - 1/(i+1))...最后连乘结果1/n
            // 证明：https://labuladong.gitee.io/algo/images/%e6%b0%b4%e5%a1%98%e6%8a%bd%e6%a0%b7/formula1.png
            if (rand() % i == 0) {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */