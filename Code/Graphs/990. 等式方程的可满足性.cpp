class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // ==如同UF的联通。对于!=就检查isConnected
        int n = equations.size();
        UF* uf = new UF(26); // 26个字母
        // 先联通全部==的部分
        for (int i = 0; i < n; i++) {
            if (equations[i][1] == '=') {
                char x = equations[i][0] - 'a';
                char y = equations[i][3] - 'a';
                uf->Union(x, y);
            }
        }
        // 然后检查!=的部分是否冲突
        for (int i = 0; i < n; i++) {
            if (equations[i][1] == '!') {
                char x = equations[i][0] - 'a';
                char y = equations[i][3] - 'a';
                // 如果其实相通，那就是矛盾了，false
                if (uf->isConnected(x, y)) {
                    return false;
                }
            }
        }
        return true;
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
};// https://leetcode.cn/problems/satisfiability-of-equality-equations/description/