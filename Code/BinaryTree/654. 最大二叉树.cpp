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
    TreeNode* build(vector<int>&nums, int start, int finish) {
        // base case
        if (start >= finish) {
            return nullptr;
        }
        // 递归构建，也包括找子数组最大值
        int maxNum = 0, maxIndex = start;
        for (int i = start; i < finish; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        // 现在找到了根节点，创建
        TreeNode* root = new TreeNode(maxNum);
        // 左闭右开且不重复计算nums[maxIndex]本身的
        root->left = build(nums, start, maxIndex);
        root->right = build(nums, maxIndex + 1, finish);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};//https://leetcode.cn/problems/maximum-binary-tree/description/