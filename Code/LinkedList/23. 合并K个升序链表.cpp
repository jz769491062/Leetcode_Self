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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* h = lists[i];
            while(h) {
                pq.push(h->val);
                h = h->next;
            }
        }
        while(!pq.empty()) {
            int v = pq.top();
            pq.pop();
            p->next = new ListNode(v);
            p = p->next;
        }
        return dummy->next;
    }
};