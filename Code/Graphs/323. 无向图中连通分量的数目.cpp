class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF* uf = new UF(n);
        for (int i = 0; i < edges.size(); i++) {
            uf->Union(edges[i][0],edges[i][1]);
        }
        return uf->Count();
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
};// https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/description/