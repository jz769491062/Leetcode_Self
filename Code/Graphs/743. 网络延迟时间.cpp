class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> graph(n + 1); // 节点从1开始，所以+1
        for (vector<int>& edge : times) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].push_back({to, weight});
        }
        vector<int> distTo = Dij(k, graph);
        int res = 0;
        // 注意节点从1开始，所以从1开始循环, 不然0是INT_MAX
        for (int i = 1; i < distTo.size(); i++) {
            if (distTo[i] == INT_MAX) {
                return -1; // 有节点无法到达
            }
            res = max(res, distTo[i]);
        }
        return res;
    }

    class State {
    public:
        int id;
        int distFromStart;
        // 每个节点储存自己的id和起始到这的距离
        State(int id, int distFromStart) {
            this->id = id;
            this->distFromStart = distFromStart;
        }
    };

    class Comp {
    public:
        bool operator()(State& A, State&B) {
            return A.distFromStart < B.distFromStart;
        }
    };

    // 返回起始节点到所有节点的最短距离
    // Dij算是利用了BFS和层序遍历
    vector<int> Dij(int start, vector<vector<vector<int>>>& graph) {
        // 初始化weight为max，然后Dij算法类似动态规划逐步缩小这些weight
        vector<int> distTo(graph.size(), INT_MAX);
        // base case
        distTo[start] = 0;
        priority_queue<State, vector<State>, Comp> pq;
        State s(start, 0);
        pq.push(s);
        while(!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            int currId = curr.id;
            int currDist = curr.distFromStart;
            // 如果比已有结果差，不必继续计算了
            if (currDist > distTo[currId]) {
                continue;
            }
            // 装载相邻节点
            for (vector<int>& neighbor : graph[currId]) {
                int nextId = neighbor[0];
                // 注意，这里用distTo[currId]作为基础，再加上去neighbor的weight
                int distToNext = neighbor[1] + distTo[currId];
                // 注意如果有所优化，才会更新，才会把节点加入队列
                // 因为加入队列条件不宽松，所以也不会出现回头路或者死循环
                // 因为dij要求节点weight不能为负数，回头路必定不是最优不会被选取
                if (distToNext < distTo[nextId]) {
                    distTo[nextId] = distToNext;
                    State better(nextId, distToNext);
                    pq.push(better);
                }
            }
        }
        return distTo;
    }

};