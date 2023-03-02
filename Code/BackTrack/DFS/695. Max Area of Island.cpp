class Solution {
vector<vector<bool>> visited;
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return 0;
        }
        if (visited[x][y]) return 0;
        visited[x][y] = true;
        if (grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + dfs(grid, x + 1, y) +
        dfs(grid, x - 1, y) +
        dfs(grid, x, y + 1) +
        dfs(grid, x, y - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};// https://leetcode.com/problems/max-area-of-island/description/