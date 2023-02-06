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
vector<TreeNode*> res;
unordered_map<string, int> memo; // 序列化后的子树 VS 他们出现过的次数

    string traverse(TreeNode* root) {
        // 技巧：利用序列化字符串本身，帮助我们找平常不好找的额外子树信息
        if (!root) return "#"; // null
        string l = traverse(root->left);
        string r = traverse(root->right);
        // 现在我们有子树信息了，构建一下子树字符串
        // 不必太在意每一时刻subTree长什么样，能准确表示一个subTree，确保map的key对于同一子树生成的字符串相等就可以了
        string subTree = l + "," + r + "," + to_string(root->val);
        // 注意C++在这一步，如果subTree不在memo里，会自动创建memo[subTree] = 0
        if (memo[subTree] == 1) {
            res.push_back(root); // 重复的子树，只加入一次进res
        }
        memo[subTree]++;
        return subTree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 怎么知道是重复的？肯定需要子树的信息，所以是后序遍历
        // 然后我们还需要所有子树的信息……那用序列化，外部结构记录一下树的结构吧
        traverse(root);
        return res;
    }
};// https://leetcode.cn/problems/find-duplicate-subtrees/description/