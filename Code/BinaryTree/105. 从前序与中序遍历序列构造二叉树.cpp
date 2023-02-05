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
// 没有重复的元素，那可以用hash匹配数值和index了
unordered_map<int, int> inOrderValToIdxMap;
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        // base case
        if (preStart >= preEnd || inStart >= inEnd) {
            return NULL;
        }
        // 前序第一个数肯定是root
        int rootVal = preorder[preStart];
        int rootInIdx = inOrderValToIdxMap[rootVal]; // 中序的root在哪个位置？
        // 现在知道左子树大小了，知道左子树递归的范围了。右子树也容易推导出来
        // preOrder: preStart + 1, preStart + leftSize
        // inOrder: inStart, rootInInx - 1
        int leftSize = rootInIdx - inStart;
        TreeNode* root = new TreeNode(rootVal);
        // 注意起止范围不能重复计算preorder[preStart]，和inOrder[rootInIdx]
        // 这里我们用左闭右开。或许左右都闭区间，[0, n - 1]更方便点
        root->left = build(preorder, preStart + 1, preStart + leftSize + 1, inorder, inStart, rootInIdx);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootInIdx + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // https://labuladong.gitee.io/algo/images/%e4%ba%8c%e5%8f%89%e6%a0%91%e7%b3%bb%e5%88%972/4.jpeg
        // 难点在于如何确认递归的范围
        // preOrder: root left right
        // inOrder: left root right
        // 那么左子树的节点数可以用inorder的root索引减去inorder的left索引获得。preOrder中left部分end不清楚, inorder中left的起止可以较清楚地计算
        for (int i = 0; i < inorder.size(); i++) {
            inOrderValToIdxMap.insert({inorder[i], i});
        }
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/