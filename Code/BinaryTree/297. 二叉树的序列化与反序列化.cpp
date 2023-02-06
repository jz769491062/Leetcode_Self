// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
// https://mp.weixin.qq.com/s/DVX2A1ha4xSecEXLxW_UsA
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
char delim = ',';
    void traverse(TreeNode* root, string& res) {
        if (!root) {
            res += "-1001";
            res += delim;
            return;
        }
        string numStr = to_string(root->val);
        res += numStr;
        res += delim;
        traverse(root->left, res);
        traverse(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 一波前序遍历，记下来即可。后序同理。还可以层序遍历。
        // https://mp.weixin.qq.com/s/DVX2A1ha4xSecEXLxW_UsA
        // 不能使用中序遍历，因为无法知道root的确切位置
        string res;
        traverse(root, res);
        res.pop_back();//移除末尾逗号分隔符
        // cout << res << endl;
        return res;
    }

    // 对于delimiter只是char的时候可以用getline，否则得用find了
    deque<int> split (const string &s, char delim) {
        deque<int> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim)) {
            result.push_back(stoi(item));
        }

        return result;
    }

    TreeNode* deserializeHelper(deque<int>& numDeque) {
        if (numDeque.empty()) return NULL;
        // 不断获取最前端的root节点以构造二叉树
        int first = numDeque.front();
        numDeque.pop_front();
        if (first == -1001) return NULL;
        TreeNode* root = new TreeNode(first);
        root->left = deserializeHelper(numDeque);
        root->right = deserializeHelper(numDeque);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = 0;
        string numStr;
        // 用deque方便front和pop_front，毕竟是前序遍历
        // 后序遍历用vector的back和pop_back就行
        deque<int> numDeque = split(data, delim);
        return deserializeHelper(numDeque);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));