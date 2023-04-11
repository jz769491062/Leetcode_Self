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
    int index = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, INT_MIN, INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, int lower, int upper) {
        if (index == preorder.size()) {
            return NULL;
        }
        int currNum = preorder[index];
        if ( currNum < lower || currNum > upper) {
            return NULL;
        }
        TreeNode* root = new TreeNode(currNum);
        // 也按照前序顺序构造节点
        index++;
        // 注意只传参index+1的效果是不一样的。我们每个新节点都应该增加index，也就是全局的index。只传参index+1是对同节点重复判断了，逻辑错误。
        root->left = dfs(preorder, lower, currNum);
        root->right = dfs(preorder, currNum, upper);
        return root;
    }
};// https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/description/