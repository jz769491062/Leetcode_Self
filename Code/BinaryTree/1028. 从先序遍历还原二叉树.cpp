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
    TreeNode* recoverFromPreorder(string traversal) {
        if (traversal.empty()) return NULL;
        stack<TreeNode*> path;
        int idx = 0;
        while (idx < traversal.size()) {
            int level = 0;
            while (traversal[idx] == '-') {
                level++;
                idx++;
            }
            int num = 0;
            while (traversal[idx] >='0' && traversal[idx] <= '9') {
                num = num * 10 + (traversal[idx] - '0');
                idx++;
            }
            TreeNode* node = new TreeNode(num);
            if (level == path.size()) {
                // 如果节点只有一个子节点，那么保证该子节点为左子节点。
                if (!path.empty()) {
                    path.top()->left = node;
                }
            } else {
                // 回溯到上一个深度
                while (level != path.size()) {
                    path.pop();
                }
                // 如果节点只有一个子节点，那么保证该子节点为左子节点。
                // 所以要么node是prev的左节点，要么是[root -> prev)路径上某个节点的右节点
                path.top()->right = node;
            }
            path.push(node);
        }
        // 记得栈先入先出，所以root在最底下
        while (path.size() > 1) {
            path.pop();
        }
        return path.top();
    }
};// https://leetcode.cn/problems/recover-a-tree-from-preorder-traversal/