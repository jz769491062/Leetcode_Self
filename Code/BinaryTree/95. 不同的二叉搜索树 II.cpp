//https://mp.weixin.qq.com/s/kcwz2lyRxxOsC3n11qdVSw
//https://leetcode.cn/problems/unique-binary-search-trees/
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
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {
            res.push_back(NULL);
            return res;
        }
        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> leftVec = build(lo, i - 1);
            vector<TreeNode*> rightVec = build(i + 1, hi);
            for (TreeNode* l : leftVec) {
                for (TreeNode* r : rightVec) {
                    // 以i为根构造，然后接上左右
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        // 其实递归结构和96差不多，只是这次实际构建节点了
        if (n == 0) return {};
        return build(1, n);
    }
};