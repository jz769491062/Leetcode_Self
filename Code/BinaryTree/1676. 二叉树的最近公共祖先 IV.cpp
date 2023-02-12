// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-iv/
// 适用于找任何数量节点的LCA
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
unordered_set<TreeNode*> st;
    TreeNode* traverse(TreeNode* root) {
        if (!root) return NULL;
        if (st.count(root)) return root;
        TreeNode* l = traverse(root->left);
        TreeNode* r = traverse(root->right);
        if (l && r) return root;
        return l ? l : r;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for (TreeNode* n : nodes) {
            st.insert(n);
        }
        return traverse(root);
    }
};