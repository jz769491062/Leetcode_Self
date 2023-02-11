// https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 两种情况的 base case
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        // 要看祖先，那得是后序
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 尽管输入合法，但是递归过程仍要考虑所有3种情况
        // pq都在root下，返回LCA；都不在root下，NULL；只有一个在root下，返回那个节点, 题目说一个节点也可以是它自己的祖先
        if (left && right) {
            return root;
        }
        if (!left && !right) {
            return NULL;
        }
        return left == NULL ? right : left;
    }
};// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/