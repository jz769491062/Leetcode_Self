class Solution {
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            if (adjList.count(u) && adjList.count(v)) {
                visited.clear();
                if (dfs(u, v)) {
                    return edge;
                }
            }
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return {};
    }

    bool dfs(int u, int v) {
        if (u == v) {
            return true;
        }
        visited.insert(u);
        for (int neighbor : adjList[u]) {
            if (!visited.count(neighbor)) {
                if (dfs(neighbor, v)) {
                    return true;
                }
            }
        }
        return false;
    }
};// https://leetcode.cn/problems/redundant-connection/description/