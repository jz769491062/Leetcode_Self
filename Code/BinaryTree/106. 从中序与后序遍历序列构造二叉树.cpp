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

    TreeNode* build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd) {
        // base case: 左右闭区间
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        // 后序最后一个数肯定是root
        int rootVal = postorder[postEnd];
        int rootInIdx = inOrderValToIdxMap[rootVal]; // 中序的root在哪个位置？
        // 现在知道左子树大小了，知道左子树递归的范围了。右子树也容易推导出来
        int leftSize = rootInIdx - inStart;
        TreeNode* root = new TreeNode(rootVal);
        // 注意起止范围不能重复计算postorder[postEnd]，和inOrder[rootInIdx]
        // 这次左右闭区间
        root->left = build(postorder, postStart, postStart + leftSize - 1, inorder, inStart, rootInIdx - 1);
        root->right = build(postorder, postStart + leftSize, postEnd - 1, inorder, rootInIdx + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 和105题很像，这次改成后序的区间
        for (int i = 0; i < inorder.size(); i++) {
            inOrderValToIdxMap.insert({inorder[i], i});
        }
        // 这次左右闭区间
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/