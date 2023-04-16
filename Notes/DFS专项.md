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

11 建图：
vector<vector<int>> adjList(n);
for (vector<int>&v : edges) {
    adjList[v[0]].push_back(v[1]);
    adjList[v[1]].push_back(v[0]);
}
vector<bool> visited(n);
if (!visited) dfs......

12 visited数组也可以用Int，有-1代表从未访问过

13 检测图中有环，还可以把visited重置为false，协助判断是否回到了原点。
/**
* @return 从顶点 u 出发的所有路径是不是有一条能够回到 u，有回路就返回 true
*/
private boolean dfs(int u, int[][] graph) {
if (visited[u] != null) {
    return visited[u];
}
// 先默认从 u 出发的所有路径有回路
visited[u] = true;
// 结点 u 的所有后继结点都不能回到自己，才能认为结点 u 是安全的
for (int successor : graph[u]) {
    if (dfs(successor, graph)) {
        return true;
    }
}
// 注意：这里需要重置
visited[u] = false;
return false;
}

14 为什么回溯不用广度优先遍历
广度优先遍历每一层需要保存所有的「状态」，如果状态空间很大，需要占用很大的内存空间；
深度优先遍历只要有路径可以走，就继续尝试走新的路径，不同状态的差距只有一个操作，而广度优先遍历在不同的层之前，状态差异很大，就不能像深度优先遍历一样，可以 使用一份状态变量去遍历所有的状态空间，在合适的时候记录状态的值就能得到一个问题的所有的解。

15 不要想当然地在backtrack使用循环。比如括号生成，是用入参的条件限制控制的，没有再循环额外生成括号的必要，每一步只加一个括号。

16 逆向思维：130. 被围绕的区域，边界上的O、以及和边界O联通的O是需要保留的，剩余的淹没。我试着正着做了，结果各种状态表示不清，visited是否需要状态重置，边界条件，如何正确保存DFS的结果……
结果还不如逆向思维：不如先遍历边界上这些O，用DFS标记和边界O联通的O为visited，那么其余的未访问的O直接淹没即可。
教训：当题目给出限制条件时，不妨试试顺着限制条件走，看看数据的状态有什么特点，然后我们取反结果，就是逆向思维了。不一定要正序做题（按照题目的限制，然后只处理那些限制下还合法的状态）。

17 DFS + 动态规划：
「无后效性」是「动态规划」的一个重要特征，也是一个问题可以使用「动态规划」解决的必要条件，「无后效性」就是字面意思：当前阶段的状态值一旦被计算出来就不会被修改，即：在计算之后阶段的状态值时不会修改之前阶段的状态值。
利用「无后效性」解决动态规划问题通常有两种表现形式：
(1) 对当前维度进行「升维」，在「自底向上递推」的过程中记录更多的信息，避免复杂的分类讨论；
(2) 固定住一种的状态，通常这种状态的形式最简单，它可以组合成复杂的状态。
理解「无后效性」需要做一些经典的使用「动态规划」解决的问题。例如：「力扣」第 62 题、第 120 题、第 53 题、第 152 题、第 300 题、第 1142 题。

18 也可以先假设条件一定满足，递归直接当做满足直接+1，然后在后序中判断条件，然后不满足条件则还原变量的方式来进行计算。
如果用前序的办法，请携带必要的额外入参，例如parent node，确保前序计算有需要的变量。
298. 二叉树最长连续序列


