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
int sum = 0; // 当前累加和
    void traverse(TreeNode* root) {
        if (!root) return;
        // 右中左中序遍历
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        // 按照通用思路去思考每个节点该做什么，并不直观，因为没有需要父节点的信息，却没有去父节点的指针
        // 观察题目例子，发现如果能按节点值降序处理每个节点的话会很方便得出结果
        // 那BST怎么降序遍历？中序遍历右中左即可！
        traverse(root);
        return root;
    }
};// 1038同此题
// https://leetcode.cn/problems/convert-bst-to-greater-tree/description/