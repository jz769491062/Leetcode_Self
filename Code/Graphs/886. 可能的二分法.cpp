class Solution {
public:
vector<bool> colors;
vector<bool> visited;
bool isGood = true;
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes) {
        // 节点从1开始计数，[n + 1]便于索引
        vector<vector<int>> res(n + 1, vector<int>(0));
        for (vector<int>& edge : dislikes) {
            int v = edge[0];
            int w = edge[1];
            // 无向图等于双向图
            res[v].push_back(w);
            res[w].push_back(v);
        }
        return res;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // dislikes本身代表的图，我们要尝试让其变成二分图
        // 变成邻接表
        vector<vector<int>> graph = buildGraph(n, dislikes);
        // 题目数字从1开始，这里也n + 1
        colors.resize(n + 1);
        visited.resize(n + 1);
        // 可能有好几个子图，所以节点都检查
        for (int v = 1; v <= n; v++) {
            if (!visited[v]) {
                bfs(v, graph);
            }
        }
        return isGood;
    }

    void bfs(int v, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int w : graph[curr]) {
                if (!visited[w]) {
                    q.push(w);
                    colors[w] = !colors[curr];
                    visited[w] = true;
                } else {
                    if (colors[w] == colors[curr]) {
                        isGood = false;
                        return;
                    }
                }
            }
        }
    }
};//https://leetcode.cn/problems/possible-bipartition/description/