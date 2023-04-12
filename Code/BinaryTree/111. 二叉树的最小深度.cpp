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
    int res = INT_MAX;
    int depth = 0;
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        depth++;
        if (!root->left && !root->right) {
            res = min(res, depth);
        }
        minDepth(root->left);
        minDepth(root->right);
        depth--;
        return res;
    }
};// https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/