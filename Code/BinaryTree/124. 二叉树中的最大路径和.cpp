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
    int res = -1001;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            res = max(res, root->val);
            return root->val;
        }
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        res = max(res, root->val + l + r);
        // 注意每对相邻节点都存在一条边才行
        return root->val + max(l, r);
    }
};// https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/