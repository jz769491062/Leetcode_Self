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
    int calcDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(calcDepth(root->left), calcDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lDepth = calcDepth(root->left);
        int rDepth = calcDepth(root->right);
        // 注意，还要递归看子节点的平衡情况
        // 每个节点 的左右两个子树的高度差的绝对值
        return abs(lDepth - rDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};// https://leetcode.cn/problems/balanced-binary-tree/description/