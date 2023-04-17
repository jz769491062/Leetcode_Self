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
    int res = 0;
    enum DIR {
        LEFT,
        RIGHT
    };
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        // 注意，一开始走过的路是0
        dfs(root, DIR::RIGHT, 0);
        dfs(root, DIR::LEFT, 0);
        return res;
    }

    void dfs(TreeNode* root, DIR nextDirection, int depth) {
        if (!root) return;
        if (nextDirection == DIR::RIGHT) {
            dfs(root->left, DIR::RIGHT, 1);
            dfs(root->right, DIR::LEFT, depth + 1);
            // 设没有走通，然后计算以另一侧为开端的情况
            // 可以说是一种动态规划的思路了：延续当前路线，还是另一个方向另起炉灶？
        } else {
            dfs(root->right, DIR::LEFT, 1);
            dfs(root->left, DIR::RIGHT, depth + 1);
            
        }
        res = max(depth, res);
    }
};// https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/description/