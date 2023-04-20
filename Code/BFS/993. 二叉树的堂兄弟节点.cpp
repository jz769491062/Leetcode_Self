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
    bool isCousins(TreeNode* root, int x, int y) {
        // bfs each node and get parent value and depth
        vector<int> xRes = bfs(root, x);
        vector<int> yRes = bfs(root, y);
        return xRes[1] == yRes[1] && xRes[0] != yRes[0];
    }

    // returns parent and depth
    vector<int> bfs(TreeNode* root, int value) {
        // node, parent, depth
        queue<tuple<TreeNode*, TreeNode*, int>> q;
        q.push({root, NULL, 0});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                tuple<TreeNode*, TreeNode*, int> curr = q.front();
                q.pop();
                TreeNode* node = get<0>(curr), *parent = get<1>(curr);
                int currDepth = get<2>(curr);
                if (node->val == value) {
                    return {parent ? parent->val : 0, currDepth};
                }
                if (node->left) {
                    q.push({node->left, node, currDepth + 1});
                }
                if (node->right) {
                    q.push({node->right, node, currDepth + 1});
                }
            }
        }
        return {-1, -1};
    }
};// https://leetcode.cn/problems/cousins-in-binary-tree/description/