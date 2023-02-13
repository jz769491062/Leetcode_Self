class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 无环就不需要visited了
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int index, vector<int>& path) {
        path.push_back(index);
        int n = graph.size();//注意是graph.size()
        // 抵达最后了，找完了一条路
        if (index == n - 1) {
            res.push_back(path);
        }
        for (int v : graph[index]) {
            traverse(graph, v, path);
        }
        // 递归结尾移除出path以便开始新path的计算
        path.pop_back();
    }
};//https://leetcode.cn/problems/all-paths-from-source-to-target/description/