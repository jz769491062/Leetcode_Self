// https://leetcode.cn/problems/min-cost-to-connect-all-points/description/
// 会超时！！！ 70/72用例
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 算一下曼哈顿距离
        int n = points.size();
        // buildGraph
        vector<vector<vector<int>>> graph(n);
        for (int i = 0; i < n; i++) {
            // 注意从i + 1开始即可，不要走回头路，就是全连接了
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                // 无向图是双向图
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }
        Prim* prim = new Prim(graph);
        return prim->GetSum();
    }
    class Prim {
        private:
        class MyComp{
        public:
            bool operator()(vector<int> const& a, vector<int> const& b) {
                return a[1] > b[1];//minHeap
            }
        };
            // 存储着to, weight
            priority_queue<vector<int>, vector<vector<int>>, MyComp> pq;
            vector<bool> inMST;
            int sum = 0;
            // graph[s] 记录节点 s 所有相邻的边，
            // 三元组 int[]{from, to, weight} 表示一条边
            vector<vector<vector<int>>> graph;
        public:
            Prim(vector<vector<vector<int>>>& graph) {
                this->graph = graph;
                int n = graph.size();
                this->inMST.resize(n);
                // 随便挑一个点开始切分即可
                // 注意我们的prim是从节点0开始计算的，buildGraph也要改成从0开始
                inMST[0] = true;
                AddCut(0);
                while(!pq.empty()) {
                    vector<int> edge = pq.top();
                    pq.pop();
                    int to = edge[0];
                    int weight = edge[1];
                    if (inMST[to]) {
                        continue;//已经在MST不要重复计算
                    }
                    // 加入MST
                    sum += weight;
                    inMST[to] = true;
                    // 加入更多切分边
                    AddCut(to);
                }
            }

            void AddCut(int node) {
                for (vector<int>& edge : graph[node]) {
                    int to = edge[0];
                    if (inMST[to]) {
                        continue;//已经在MST不要重复计算,防环
                    }
                    pq.push(edge);
                }
            }

            int GetSum() {
                return this->sum;
            }
    };
};