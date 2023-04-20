/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<int> q;
        queue<Node*> nodeQ;
        q.push(root->val);
        nodeQ.push(root);
        vector<vector<int>> res;
        while (!nodeQ.empty()) {
            int sz = nodeQ.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                Node* curr = nodeQ.front();
                nodeQ.pop();
                int value = q.front();
                q.pop();
                level.push_back(value);
                for (Node* n : curr->children) {
                    nodeQ.push(n);
                    q.push(n->val);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/