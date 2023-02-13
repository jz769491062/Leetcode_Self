// https://leetcode.cn/problems/count-complete-tree-nodes/
/* 注意不是满二叉树！完全二叉树的定义如下：
在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。*/ 
// 完全二叉树适用于数组实现二叉堆。
// 当然可以像普通二叉树一样计算节点个数：
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
// 不过也可具体问题具体分析：
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
    int countNodes(TreeNode* root) {
        TreeNode* l = root, *r = root;
        int heightL = 0, heightR = 0;
        while (l) {
            l = l->left;
            heightL++;
        }
        while (l) {
            r = r->right;
            heightR++;
        }
        // 最左最右高度相等，是满二叉树
        if (heightL == heightR) {
            return pow(2, heightL) - 1;
        }
        // 否则按普通二叉树算
        // 关键点在于，这两个递归只有一个会真的递归下去，另一个一定会触发 hl == hr 而立即返回，不会递归下去。
        // 因为完全二叉树的性质：一棵完全二叉树的两棵子树，至少有一棵是满二叉树
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};