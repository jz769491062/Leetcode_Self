class Solution {//https://mp.weixin.qq.com/s/dJ9gqR3RVoeGnATlpMG39w
public://https://leetcode.cn/problems/connecting-cities-with-minimum-cost/description/
// Kruskal 最小生成树算法
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int> const& l,vector<int> const& r) {
            return l[2] < r[2];
        });
        // 注意节点值从1开始的
        UF* uf = new UF(n + 1);
        int sum = 0;
        for (int i = 0; i < connections.size(); i++) {
            int p = connections[i][0];
            int q = connections[i][1];
            if (uf->isConnected(p, q)) {
                // 注意，产生了环，而不是发现了终点。不可以加入MST
                continue;
            }
            uf->Union(p, q);
            sum += connections[i][2];
        }
        // 注意，我们Union的是1~n,0没有用到，所以Count这里检查2而不是1
        if (uf->Count() == 2) return sum;
        else return -1;
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
};