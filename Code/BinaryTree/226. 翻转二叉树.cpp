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
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        traverse(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        // 能不能遍历解决？可以。
        // 每个节点干什么？交换自己的left,right
        // 什么顺序？前后好像都行。
        // 为啥不能中序？如题目[4,2,7,1,3,6,9]这个，2作为左节点交换完了一次，然后在4把2和7交换，然后2作为右节点又交换回去了……结果就是最后一层一边完全没换，另一边换了两次和原来一样
        // 不能中序是因为要交换左右2节点，我们同时依赖左右2节点的信息，所以要么都还没处理，要么都已经处理了，所以只能前序和后序
        traverse(root);
        return root;

    }
};//https://leetcode.cn/problems/invert-binary-tree/description/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 能不能递归解决？可以
        // 每个节点做什么？交换左右节点。
        // 什么顺序？后序显然可以，完成左右子树的交换后，得到左右节点，然后直接换。
        if (!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

class Solution {
public:
TreeNode* r = NULL;
    TreeNode* invertTree(TreeNode* root) {
        // 能不能递归解决？可以
        // 每个节点做什么？交换左右节点。
        // 这样前序也不是不行，类似遍历了
        if (!root) return NULL;
        if (!r) r = root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return r;
    }
};