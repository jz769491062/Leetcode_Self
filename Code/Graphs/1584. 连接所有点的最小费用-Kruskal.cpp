class Solution {//https://mp.weixin.qq.com/s/dJ9gqR3RVoeGnATlpMG39w
public:// https://leetcode.cn/problems/min-cost-to-connect-all-points/description/
// 本题m == n^2 所以O(n^2logn)
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 算一下曼哈顿距离，剩下的就是Kruskal算法，和1135一致
        int n = points.size();
        // 储存节点i, j, 之间距离
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            // 注意从i + 1开始即可，不要走回头路，就是全连接了
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end(), [](vector<int> const& l, vector<int> const& r) {
            return l[2] < r[2];
        });
        // 节点使用的索引，就不用+ 1了
        UF *uf = new UF(n);
        int sum = 0;
        for (vector<int> v : edges) {
            int p = v[0];
            int q = v[1];
            if (uf->isConnected(p, q)) {
                continue;
            }
            uf->Union(p, q);
            sum += v[2];
        }
        return uf->Count() == 1 ? sum : -1;
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