class Solution {
public://https://mp.weixin.qq.com/s/dJ9gqR3RVoeGnATlpMG39w
    bool validTree(int n, vector<vector<int>>& edges) {
        // 可以理解为确认树有没有环
        // 并查集UF可以帮助。如果俩节点已经在一个分量里了，那就是有环的
        UF* uf = new UF(n);
        for (int i = 0; i < edges.size(); i++) {
            int p = edges[i][0];
            int q = edges[i][1];
            if (uf->isConnected(p, q)) return false;
            uf->Union(p, q);
        }
        // 注意，我们确认的是一棵树，所以最后要确认是不是只剩下一个连通分量
        return uf->Count() == 1;
    }
    class UF {
    private:
        int count;
        vector<int> parent;
    public:
        int Count() {
            return count;
        }

        UF (int n) {
            count = n;
            parent.resize(n);
            for (int i = 0; i < parent.size(); i++) {
                parent[i] = i;
            }
        }
        
        int Find(int x) {
            if (parent[x] != x) {
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }

        void Union (int p, int q) {
            int rootP = Find(p);
            int rootQ = Find(q);
            if (rootP == rootQ) return;
            parent[rootQ] = rootP;
            count--;
        }

        bool isConnected (int p, int q) {
            int rootP = Find(p);
            int rootQ = Find(q);
            return rootP == rootQ;
        }
    };
};// https://leetcode.cn/problems/graph-valid-tree/description/