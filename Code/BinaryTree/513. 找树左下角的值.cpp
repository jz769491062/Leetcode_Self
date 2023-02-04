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
// 反向的层序遍历，从右到左一层一层，最后一个就是左下角的节点了
    int maxDepth = 0;
    int currDepth = 0;
    TreeNode* res = NULL;
    int findBottomLeftValue(TreeNode* root) {
        traverse(root);
        return res->val;
    }
    void traverse(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode->right) {
                q.push(currNode->right);
            }
            if (currNode->left) {
                q.push(currNode->left);
            }
            res = currNode;
        }
    }
};//https://leetcode.cn/problems/find-bottom-left-tree-value/