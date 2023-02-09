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
    bool validBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        // 保证root在允许的最小、最大开区间内, 注意用的>=和<=
        if (minNode && root->val <= minNode->val) return false;
        if (maxNode && root->val >= maxNode->val) return false;
        return validBSTHelper(root->left, minNode, root) && validBSTHelper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        // 注意是root的整颗子树的节点都要满足大小条件
        // 那我们得设法保留当前路径上遇到的最小节点和最大节点
        return validBSTHelper(root, NULL, NULL);
    }
};//https://leetcode.cn/problems/validate-binary-search-tree/description/