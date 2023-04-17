// 同1123https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/
// https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/description/
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
    // 保存所有最深节点用，节点->深度的map
    unordered_map<TreeNode*, int> depthMap;
    int maxDepth = 0;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;
        depthMap[NULL] = 0;
        calcDepth(root, NULL);
        for (auto it : depthMap) {
            maxDepth = max(maxDepth, it.second);
        }
        return dfs(root);
    }

    void calcDepth(TreeNode* node, TreeNode* parent) {
        if (node) {
            depthMap[node] = depthMap[parent] + 1;
            calcDepth(node->left, node);
            calcDepth(node->right, node);
        }
    }

    TreeNode* dfs(TreeNode* node) {
        if (!node) {
            return NULL;
        }
        if (depthMap[node] == maxDepth) {
            return node;
        }
        // 子树是否有最深节点？左右多有那就是找到了最小子树，只有一个就返回那一个节点
        TreeNode* l = dfs(node->left);
        TreeNode* r = dfs(node->right);
        if (l && r) {
            return node;
        }
        if (l) return l;
        if (r) return r;
        return NULL;
    }
};