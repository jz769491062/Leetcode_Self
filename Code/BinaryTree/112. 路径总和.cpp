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
    int sum = 0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        sum += root->val;
        if (sum == targetSum && (!root->left && !root->right)) {
            return true;
        }
        bool has = hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        sum -= root->val;
        return has;
    }
};// https://leetcode.cn/problems/path-sum/description/