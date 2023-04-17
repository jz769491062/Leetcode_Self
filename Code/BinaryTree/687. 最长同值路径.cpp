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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* n) {
        if (!n) return 0;
        // if (!n->left && !n->right) {
        //     return 1;
        // }// 错误的，只有一个节点还是没有路径啊！
        int l = dfs(n->left);
        int r = dfs(n->right);
        int l1 = 0, r1 = 0;
        // 只有父子相等的时候才考虑带上子节点结果，并且+1！
        if (n->left) {
            if (n->val == n->left->val) {
                l1 = l + 1;
            }
        }
        if (n->right) {
            if (n->val == n->right->val) {
                r1 = r + 1;
            }
        }
        res = max(res, l1 + r1);
        return max(l1, r1);
    }
};// https://leetcode.cn/problems/longest-univalue-path/solutions/1790729/zui-chang-tong-zhi-lu-jing-by-leetcode-s-hgfk/