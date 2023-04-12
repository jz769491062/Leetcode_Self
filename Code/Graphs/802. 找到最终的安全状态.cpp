class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, visited)) {
                continue;
            }
            // 其实就是找无环的节点
            res.push_back(i);
        }
        return res;
    }

    bool dfs(vector<vector<int>>& graph, int curr, vector<int>& visited) {
        if (visited[curr] != -1) {
            // 如果是环路，那么这里会返回true
            // 没有环路的话，每次都是新节点，那不会走这里, 也就最终能够返回false
            return visited[curr];
        }
        visited[curr] = true;
        for (int neighbor : graph[curr]) {
            if (dfs(graph, neighbor, visited)) {
                return true;
            }
        }
        // 所有neighbor看完了，没有环
        visited[curr] = false;
        return false;
    }
};// https://leetcode.cn/problems/find-eventual-safe-states/description/