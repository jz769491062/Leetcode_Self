1 如果不需要额外的入参或者变量记录当前节点遍历的状态的话，不需要创建helper函数。
100. 相同的树

2 最简单的回溯：104. 二叉树的最大深度 , 注意维护的depth可以说是回溯每一步的一个状态，然后res记录max。
 前序+1，中序更新max，后序回退状态。

3 很多DFS题，实际上就是从树的底端叶子节点开始思考子问题。!root, left和right有无的判断，无非就这些。

4 二叉树框架：
起手if (!root)
想好前序后序还是中序（前中后序都是DFS）
只看当前节点、左、右这3个节点的所有可能性，记录需要的数字。
交给递归做剩下的，反正一开始有!root兜底了。


5 求节点数字和的题，一定是前序的，因为你要知道根节点是什么数字才能正确计算出最后的结果。
因为sum一开始是0，所以更新公式应该是sum = sum * 10 + root->val，放在前序，每深入一层就会再*10，搞定。
129. 求根节点到叶节点数字之和

6 看祖先节点的题目，是后序的，自底向上摸的。没摸到所需节点就是NULL，摸到了节点就返回那个节点，保存到变量里，告诉更上层的递归当前子树已经发现了目标。当所有目标节点都发现了(都不是NULL了)，当前root就是所需祖先。

7 对于有二叉搜索树性质的，可以传入lower和upper来帮助确定节点值合法性，初始化为INT_MIN,MAX.

8 利用栈来记录、回退到之前的节点。
但是!利用栈迭代进行遍历的时候，因为先入先出，所以要反着进栈！前序遍历中左右，那加入栈的顺序应该是右左中！
结合题目需要，想想放入栈的顺序是否OK。
vector<int> preorderTraversal(TreeNode* root) {
    vector<TreeNode*> stk;
    stk.push_back(root);
    vector<int> res;
    while (!stk.empty()) {
        TreeNode* node = stk.back();
        stk.pop_back();
        if (node) {
            if (node->right) {
                stk.push_back(node->right);
            }
            if (node->left) {
                stk.push_back(node->left);
            }
            res.push_back(node->val);
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> res;
    TreeNode* curr = root;
    while (!stk.empty() || curr) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
// 另一种inOrder
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    while (root || !s.empty()) {
        if(root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    TreeNode* pre = NULL;
    vector<int> res;
    stack<TreeNode*> s;
    while (root || !s.empty()) {
        if(root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            // root->right == pre 已经访问过右子树了
            // !root->right现在左右都空 或者 左访问过右空 了
            // 然后才轮到mid
            if (!root->right || root->right == pre) {
                res.push_back(root->val);
                s.pop();
                pre = root;
                root = NULL;
            } else {
                root = root->right;
            }
        }
    }
    return res;
}

9 N叉树遍历：
void dfs(Node* root) {
    if (root == NULL) return;
    res.push_back(root->val);
    for (Node* chi : root->children) {
        dfs(chi);
    }
}
vector<int> preorder(Node* root) {
    dfs(root);
    return res;
}

10 DFS的一些应用：
获取图/树的一些属性
计算无向图的连通分量
检测图中是否有环
二分图
获得问题所有的解（回溯）

