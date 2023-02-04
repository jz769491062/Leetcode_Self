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
    void flatten(TreeNode* root) {
        // 函数返回void,也就是希望我们原地拉平，那就不要遍历新创链表了
        // 那就只能递归分解了
        // 对于每一个节点，我们希望他左子树和右子树都是拉平的
        // 怎么拉平呢？
        // 先右子树接到左子树下面，然后题目要求链表一路向右，那就再把接完后的整个左子树当右子树使用
        // 后序递归，我们需要左右子树信息
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        // 如何拉平：
        // 保存一下原左右子树的节点
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        // 1 原左子树当新右子树用
        root->left = NULL;
        root->right = l;// 还有r作为右子树的节点，此处不必担心
        // 2 找到原左子树的最下面，在这里就是一路向右
        TreeNode* temp = root;
        while (temp->right) {
            temp = temp->right;
        }
        // 3 原左子树最下方接上原右子树
        temp->right = r;
    }
};// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/