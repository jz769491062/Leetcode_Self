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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val); // 在NULL位置插入
        // 注意是要对左右子节点进行赋值，把新插入的节点给接上，也保证原结构
        if (root->val < val) root->right =  insertIntoBST(root->right, val);
        if (root->val > val) root->left =  insertIntoBST(root->left, val);
        return root;
    }
};