class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<vector<double>>> graph(n); // prob不一定整数，所以先都用double了
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double prob = succProb[i];
            // 无向图是双向图
            graph[from].push_back({(double)to, prob});
            graph[to].push_back({(double)from, prob});
        }
        return Dij(start, end, graph);
    }

    class State {
    public:
        int id;
        double probFromStart;
        State(int id, double prob) {
            this->id = id;
            this->probFromStart = prob;
        }
    };

    class Comp {
    public:
        bool operator()(State& A, State& B) {
            // 降序排列，优先找概率最大的路径，减去不必要的反复更新次数，提高运行效率
            return A.probFromStart < B.probFromStart; 
        }
    };

    double Dij(int start, int end, vector<vector<vector<double>>>& graph) {
        vector<double> probTo(graph.size(), -1);// 这次找概率最大，所以初始值设成一个不可能的最小值
        // base case
        probTo[start] = 1; // 注意记得也初始化Probto[start]数组
        priority_queue<State, vector<State>, Comp> pq;
        State s(start, 1);
        pq.push(s);
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            int currId = curr.id;
            double currProb = curr.probFromStart;
            if (currId == end) return currProb;
            // 已经有概率更大的了，跳过这个路线
            if (currProb < probTo[currId]) {
                continue; 
            }
            for (vector<double>& neighbor : graph[currId]) {
                int nextId = (int)neighbor[0];
                double probToNext = probTo[currId] * neighbor[1];
                if (probToNext > probTo[nextId]) {
                    probTo[nextId] = probToNext;
                    State better(nextId, probToNext);
                    pq.push(better);
                }
            }
        }
        return 0;//start到不了end
    }
};