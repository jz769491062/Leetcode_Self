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
    int res = 0;
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        res = max(res, ld + rd); // 改良：直接在子问题就更新好答案
        return max(ld, rd) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }
};//https://leetcode.cn/problems/diameter-of-binary-tree/description/
