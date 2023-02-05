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
// 还是数字不重复，继续用map索引
unordered_map<int, int> postValToIdxMap;
    TreeNode* build (vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        // base case 左右闭区间
        if (preStart > preEnd) {
            return NULL;
        }
        // base case 只有一个元素的情况
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int rootVal = preorder[preStart];
        // 后序的左子树的右边界
        int postLeftSubtreeRightBound = postValToIdxMap[preorder[preStart + 1]];
        // 这样左子树元素个数就确认了
        // 注意，这个leftSize是在前序后序都通用的
        int leftSize = postLeftSubtreeRightBound - postStart + 1;
        TreeNode* root = new TreeNode(rootVal);
        // 左右闭区间
        root->left = build(preorder, preStart + 1, preStart + leftSize, 
            postorder, postStart, postLeftSubtreeRightBound);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, 
            postorder, postLeftSubtreeRightBound + 1, postEnd - 1);// 注意postorder[postEnd]和preorder[preStart]是一样的，递归时不要重复计算这个元素
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // 没有中序遍历的话，我们不能清楚计算一子树有多少节点，意味着有多种可能性
        // 和105/106题的本质不同
        // 两头看
        // pre: root left right
        // post: left right root
        // 那么倒着看post我们就能先摸到右子树，正着看pre我们就能先摸到左子树
        // 进一步说，从root开始，preorder第一层的root->left，在postorder倒着遍历找root->left的值，那个值就是左右子树的分界线，是preorer左子树第一个值，再+1就是preOrder右子树。
        // 所以map一下数值和Index，依然有用武之地，避免每次递归重复遍历
        for (int i = 0; i < postorder.size(); i++) {
            postValToIdxMap.insert({postorder[i], i});
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/