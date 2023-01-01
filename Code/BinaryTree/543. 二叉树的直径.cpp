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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // 直径 = 左右两子树最大深度之和
        // 需要左右两子树的结果，所以需要在maxDepth的后序计算直径
        if (!root) return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        int currDiameter = leftMax + rightMax;
        res = max(res, currDiameter);
        // 分解思路，继续计算子问题，diameterOfBinaryTree的前序
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return res;//return无意义，理解用
    }
};//https://leetcode.cn/problems/diameter-of-binary-tree/description/

//优化后更好的：
// // 记录最大直径的长度
// int maxDiameter = 0;

// public int diameterOfBinaryTree(TreeNode root) {
//     maxDepth(root);
//     return maxDiameter;
// }

// int maxDepth(TreeNode root) {
//     if (root == null) {
//         return 0;
//     }
//     int leftMax = maxDepth(root.left);
//     int rightMax = maxDepth(root.right);
//     // 后序位置，顺便计算最大直径
//     int myDiameter = leftMax + rightMax;
//     maxDiameter = Math.max(maxDiameter, myDiameter);

//     return 1 + Math.max(leftMax, rightMax);
// }
