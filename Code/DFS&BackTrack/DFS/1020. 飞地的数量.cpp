class Solution {
    int m, n, res = 0;
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        for (vector<int>& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (inArea(nx, ny) && grid[nx][ny] == 1) {
                dfs(grid, nx, ny);
            }
        }
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};// https://leetcode.cn/problems/number-of-enclaves/description/