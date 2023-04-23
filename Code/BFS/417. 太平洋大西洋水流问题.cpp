class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> vis1, vis2;
    vector<vector<int>> pacific, atlantic;
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vis1.resize(m, vector<bool>(n));
        vis2.resize(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    vis1[i][j] = true;
                    pacific.push_back({i, j});
                }
                if (i == m - 1 || j == n - 1) {
                    vis2[i][j] = true;
                    atlantic.push_back({i, j});
                }
            }
        }
        // 直接利用就在海边的这些格子开始BFS
        bfs(heights, pacific, vis1);
        bfs(heights, atlantic, vis2);
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, vector<vector<bool>>& visited) {
        while (!ocean.empty()) {
            int x = ocean.back()[0];
            int y = ocean.back()[1];
            int val = heights[x][y];
            ocean.pop_back();
            for (vector<int>& di: dir) {
                int nx = x + di[0], ny = y + di[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                // 只有高处能往低流
                if (visited[nx][ny] || heights[nx][ny] < val) continue;
                ocean.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
};// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/