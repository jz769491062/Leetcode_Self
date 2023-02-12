// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/*
递归解决方式

需要保存一个res为根节点：作为一个类里的变量
递归函数：实现判断当前节点curr是否包含p或者q
空的：返回false
求解curr->left和curr->right的情况，返回值为l和r，这里需要讨论了
l==r==true,说明左右分支包含了p和q（不管在哪边把），curr就是结果
l==true || r==true： 如果这个时候curr的结点等于p或者q，那么也满足，curr就是结果
总结下来，条件就是 l || r || curr==q || curr==p
*/
TreeNode* res = NULL;
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        if (!p && !q) return false;
        bool left = traverse(root->left, p, q);
        bool right = traverse(root->right, p, q);
        if (left && right) {
            res = root;
        } else if ((left || right) && (root == p || root == q))
        {
            res = root;
        }
        // 这部分可以处理pq有一不在二叉树的场景
        return left || right || root == p || root == q;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return res;
    }
};