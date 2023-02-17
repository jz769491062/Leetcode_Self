class Prim {
        private:
        class MyComp{
        public:
            bool operator()(vector<int> const& a, vector<int> const& b) {
                return a[2] > b[2];//minHeap
            }
        };
            // 存储着edge三元组
            priority_queue<vector<int>, vector<vector<int>>, MyComp> pq;
            vector<bool> inMST;
            int sum = 0;
            // graph[s] 记录节点 s 所有相邻的边，
            // 三元组 int[]{from, to, weight} 表示一条边
            vector<vector<vector<int>>> graph;
        public:
            Prim(vector<vector<vector<int>>> graph) {
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
                    int to = edge[1];
                    int weight = edge[2];
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
                // 是要把edge加入pq的，所以不要用引用，就copy
                for (vector<int> edge : graph[node]) {
                    int to = edge[1];
                    if (inMST[to]) {
                        continue;//已经在MST不要重复计算,防环
                    }
                    pq.push(edge);
                }
            }

            int GetSum() {
                return this->sum;
            }

            bool AllConnected() {
                // 可以考虑inMST优化成unordered_map提高运行速度?
                for (int i = 0; i < inMST.size(); i++) {
                    if (!inMST[i]) return false;
                }
                return true;
            }
    };