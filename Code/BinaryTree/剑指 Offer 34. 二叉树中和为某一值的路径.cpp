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
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return {};
        path.push_back(root->val);
        backtrack(root, target, root->val);
        return res;
    }

    void backtrack(TreeNode* root, int target, int currSum) {
        if (!root->left && !root->right) {
            if (currSum == target) {
                res.push_back(path);
            }
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            backtrack(root->left, target, currSum + (root->left->val));
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            backtrack(root->right, target, currSum + (root->right->val));
            path.pop_back();
        }
    }
};// https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/description/?company_slug=huawei