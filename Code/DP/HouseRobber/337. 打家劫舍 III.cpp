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
unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        // 如果决定偷当前房子，得看看下下两间房的数值
        // 如果决定不偷当前房子，那可以偷下一层
        // 同一层的节点实质上是一个整体，我们决定偷不偷这一层
        if (!root) return 0;
        if (memo.count(root)) return memo[root];
        int ll = root->left ? rob(root->left->left) + rob(root->left->right) : 0;
        int rr = root->right ? rob(root->right->left) + rob(root->right->right) : 0;
        int toRob = root->val + ll + rr;
        int notRob = rob(root->left) + rob(root->right);
        int res = max (toRob, notRob);
        memo[root] = res;
        return res;
    }
};// https://leetcode.cn/problems/house-robber-iii/description/

class Solution {
public:
/* 返回一个大小为 2 的数组 arr
arr[0] 表示不抢 root 的话，得到的最大钱数
arr[1] 表示抢 root 的话，得到的最大钱数 */
    vector<int> dp(TreeNode* root) {
        if (!root) return {0, 0};
        // 从叶子开始，以保证不抢[0]抢[1]的初始化，和递归公司的正确推演
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int toRob = root->val + left[0] + right[0];//抢了这层无法抢下层，所以用[0]
        // 对于左右分支，分别判断抢下家还是不抢下家
        // bottom-up所以这些left, right值是已经赋值好了的
        int notRob = max(left[1], left[0]) + max(right[0], right[1]); // 注意，不抢的话，下家依然可抢可不抢
        return {notRob, toRob};
    }

    int rob(TreeNode* root) {
        // 优雅的解法：比较抢root和不抢root哪个更大
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
};