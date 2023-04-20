/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return {};
        q.push(root);
        bool rightStart = false;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> oneLevel;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                oneLevel.push_back(curr->val);
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (rightStart) {
                reverse(oneLevel.begin(), oneLevel.end());
            }
            res.push_back(oneLevel);
            rightStart = !rightStart;
        }
        return res;
    }
};// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/