class Solution {
public:
vector<bool> colors; // 尝试着色, true false 2 colors
vector<bool> visited;
bool isGood = true; // 是否满足二分图
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.resize(n);
        visited.resize(n);
        // 因为图不一定是联通的，可能存在多个子图
        // 所以要把每个节点都作为起点进行一次遍历
        // 如果发现任何一个子图不是二分图，整幅图都不算二分图
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                traverse(graph, v);
            }
        }
        return isGood;
    }

    void traverse(vector<vector<int>>& graph, int v) {
        if (!isGood) return;
        // 注意visited前置，先标记访问过本节点，再去邻居。这样有环的时候不会无限循环
        visited[v] = true;
        for (int nei : graph[v]) {
            // 没访问过就涂不一样的颜色，访问过就判断颜色是否满足二分
            if (!visited[nei]) {
                colors[nei] = !colors[v];
                traverse(graph, nei);
            } else {
                if (colors[nei] == colors[v]) {
                    isGood = false;
                    return;
                }
            }
        }
    }
};// https://leetcode.cn/problems/is-graph-bipartite/description/