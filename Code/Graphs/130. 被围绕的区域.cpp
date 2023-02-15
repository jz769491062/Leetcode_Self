class Solution {//https://leetcode.cn/problems/surrounded-regions/
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        // 把不需要替换的O，统统连接到dummy，除了连接到dummy的这些O，剩下的全部变X
        UF* uf = new UF(m * n + 1);
        int dummy = m * n;
        // 将首列和末列的 O 与 dummy 连通
        // 注意使用正确的board x,y 索引和值
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                uf->Union(i * n, dummy);
            if (board[i][n - 1] == 'O')
                uf->Union(i * n + n - 1, dummy);
        }
        // 将首行和末行的 O 与 dummy 连通
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                uf->Union(j, dummy);
            if (board[m - 1][j] == 'O')
                uf->Union(n * (m - 1) + j, dummy);
        }
        vector<vector<int>> d = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        // 处理非边界的格子们, 1 ~ n - 2
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (board[i][j] == 'O')
                    // 将此 O 与上下左右的 O 连通，这样不是被X围绕的O有机会和dummy联通
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf->Union(x * n + y, i * n + j);
                    }
        // 所有不和 dummy 连通的 O，说明是被X围绕的，都要被替换
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (!uf->isConnected(dummy, i * n + j))
                    board[i][j] = 'X';
    }

    class UF {
    private:
        int count;// 连通分量，或者说有多少组
        vector<int> parent;
    public:
        UF(int n) {
            this->count = n;
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                // 初始情况，节点的parent就是自己
                parent[i] = i;
            }
        }

        int Find(int x) {
            if (parent[x] != x) {
                // 这里的递归路径压缩非常重要！！！
                // 这个递归效果是，原来是个链表，直接把UF树拉平成一个水母形状，
                // 原来N层现在只剩2层，第一层一个parent，第二层是其余节点
                // 因为UF我们只关心联通，不关心节点之间以什么样的路径进行联通，所以能统筹parent就统筹parent
                // find均摊后的运行时是O(1)
                // 这个路径压缩让Union, Find, Connected均摊都变成O(1)了
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }

        int Count() {
            return count;
        }

        void Union(int p, int q) {
            int rootP = Find(p);
            int rootQ = Find(q);
            // 已经联通就不必改动
            if (rootP == rootQ) {
                return;
            }
            // 由于Find直接把UF树拉平了，就没必要记录一下每个树的size然后挑一个小的接上了
            parent[rootQ] = rootP;
            // 记得降低连通分量数量
            count--;
        }

        bool isConnected(int p, int q) {
            int rootP = Find(p);
            int rootQ = Find(q);
            return rootP == rootQ;
        }
    };
};