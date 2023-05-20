class Solution {
public:
int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int N = graph.size();
    vector<int> clean(N, 1);
    for (int x : initial) {
        clean[x] = 0;
    }

    // For each node u in initial, dfs to find
    // 'seen': all nodes not in initial that it can reach.
    vector<vector<int>> infectedBy(N);
    for (int i = 0; i < N; ++i) {
        infectedBy[i] = vector<int>();
    }

    for (int u : initial) {
        unordered_set<int> seen;
        dfs(graph, clean, u, seen);
        for (int v : seen) {
            infectedBy[v].push_back(u);
        }
    }

    // For each node u in initial, for every v not in initial
    // that is uniquely infected by u, add 1 to the contribution for u.
    vector<int> contribution(N, 0);
    for (int v = 0; v < N; ++v) {
        if (infectedBy[v].size() == 1) {
            contribution[infectedBy[v][0]]++;
        }
    }

    // Take the best answer.
    sort(initial.begin(), initial.end());
    int ans = initial[0], ansSize = -1;
    for (int u : initial) {
        int score = contribution[u];
        if (score > ansSize || (score == ansSize && u < ans)) {
            ans = u;
            ansSize = score;
        }
    }
    return ans;
}

void dfs(vector<vector<int>>& graph, vector<int>& clean, int u, unordered_set<int>& seen) {
    for (int v = 0; v < graph.size(); ++v) {
        if (graph[u][v] == 1 && clean[v] == 1 && seen.count(v) == 0) {
            seen.insert(v);
            dfs(graph, clean, v, seen);
        }
    }
}
};// https://leetcode.cn/problems/minimize-malware-spread-ii/description/