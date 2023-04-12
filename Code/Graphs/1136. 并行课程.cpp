class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, set<int>> adjList;
        vector<int> indegree(n + 1);
        for (vector<int>& v : relations) {
            adjList[v[1]].insert(v[0]);
            indegree[v[0]]++;
        }
        // vector<int> visited(n + 1);
        // for (int i = 1; i <= n; i++) {
        //     if (dfs(adjList, visited, i, 1)) {
        //         return -1;
        //     }
        // }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        if (q.empty()) {
            return -1;
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adjList[curr]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            res++;
        }
        // 有环
        for (int i : indegree) {
            if (i > 0) {
                return -1;
            }
        }
        return res;
    }

    bool dfs(unordered_map<int, set<int>>& adjList, vector<int>& visited, int idx, int depth) {
        if (visited[idx] == 1) {
            return true;
        }
        if (visited[idx] == 2) {
            return false;
        }
        visited[idx] = 1;
        for (int neighbor : adjList[idx]) {
            if (dfs(adjList, visited, neighbor, depth + 1)) {
                return true;
            }
        }
        visited[idx] = 2;
        return false;
    }
};