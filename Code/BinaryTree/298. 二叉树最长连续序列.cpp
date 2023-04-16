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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        dfs(root, NULL, 0);
        return res;
    }

    void dfs(TreeNode* node, TreeNode* parent, int currLen) {
        if (!node) {
            return;
        }
        currLen = (parent && parent->val + 1 == node->val) ? currLen + 1 : 1;
        res = max(res, currLen);
        dfs(node->left, node, currLen);
        dfs(node->right, node, currLen);
    }
};// https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence/

// bottom-up
class Solution {
    int res = 0;
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        if (root->left && root->val + 1 != root->left->val) {
            l = 1;
        }
        if (root->right && root->val + 1 != root->right->val) {
            r = 1;
        }
        int len = max(l, r);
        res = max(res, len);
        return len;
    }
};