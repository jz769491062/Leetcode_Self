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
int depth = 0;
    int maxDepth(TreeNode* root) {
        if (!root) return depth;
        //现在开始进入二叉树，前序，加depth
        //一棵二叉树的前序遍历结果 = 根节点 + 左子树的前序遍历结果 + 右子树的前序遍历结果
        depth++;
        maxDepth(root->left);
        // 只要在进入二叉树节点后，退出二叉树节点前，在任意位置更新res皆可
        // BST的中序遍历 = 遍历有序数组
        res = res < depth? depth : res;
        maxDepth(root->right);
        //现在退出二叉树节点，后序，还原depth以备其他子问题遍历
        //前序位置的代码只能从函数参数中获取父节点传递来的数据，
        //而后序位置的代码不仅可以获取参数数据，还可以获取到子树通过函数返回值传递回来的数据
        depth--;
        return res;//其实这return没用，主要是理解用才这么写。正确代码见下
    }
    // int maxDepth(TreeNode* root) {
    //     if (root) {
    //         int leftMax = maxDepth(root->left);
    //         int rightMax = maxDepth(root->right);
    //         return 1 + max(leftMax, rightMax);
    //     }
    //     return 0;
    // }
};//https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/