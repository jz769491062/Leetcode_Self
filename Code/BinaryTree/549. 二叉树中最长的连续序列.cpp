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
        dfs(root);
        return res;
    }

    // 两个数: 递增的长度和递减的长度
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        int inc = 1, dec = 1;
        if (root->left) {
            vector<int> l = dfs(root->left);
            if (root->val == root->left->val + 1) {
                dec = l[1] + 1;
            } else if (root->val == root->left->val - 1) {
                inc = l[0] + 1;
            }
        }
        if (root->right) {
            vector<int> r = dfs(root->right);
            if (root->val == root->right->val + 1) {
                dec = max(dec, r[1] + 1);
            } else if (root->val == root->right->val - 1) {
                inc = max(inc, r[0] + 1);
            }
        }
        res = max(res, dec + inc - 1); // dec和inc重复计算当前节点所以-1
        return {inc, dec};
    }
};// https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence-ii/description/