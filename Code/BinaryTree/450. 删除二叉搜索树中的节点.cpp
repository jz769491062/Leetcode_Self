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
    TreeNode* findMax(TreeNode* n) {
        while(n->right) n = n->right;
        return n;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            // 3种情况：目标节点左右NULL，只有一个子节点，或者左右多有
            // 都是NULL直接删除即可return null, 只有一个子节点就return另一个
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // 左右都有，我们需要找到左子树最大节点，或者右子树最小节点
            TreeNode* maxNode = findMax(root->left);
            // 然后删除那个节点
            root->left = deleteNode(root->left, maxNode->val);
            // 然后替换掉root
            maxNode->left = root->left;
            maxNode->right = root->right;
            root = maxNode;
        }
        else if (root->val < key) root->right =  deleteNode(root->right, key);
        else if (root->val > key) root->left =  deleteNode(root->left, key);
        return root;
    }
};// https://leetcode.cn/problems/delete-node-in-a-bst/description/