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
int res = 0;
int currRank = 0;
    void traverse(TreeNode* root, int k) {
        if (!root) return;
        traverse(root->left, k);
        // 额外变量记录当前第几小
        currRank++;
        if (k == currRank) {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // 中序，事实上就是BST升序排序
        traverse(root, k);
        return res;
    }
};// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/