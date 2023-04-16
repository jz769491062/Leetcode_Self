class Solution {
    vector<vector<bool>> visited;
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return;
        }
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            dfs(grid, x + 1, y);
            dfs(grid, x - 1, y);
            dfs(grid, x, y + 1);
            dfs(grid, x, y - 1);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n));
        // 淹掉上下
        for (int i = 0; i < n;i++) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        // 淹掉左右
        for (int i = 0; i < m;i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        // 统计剩余岛屿数量即可
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/number-of-closed-islands/