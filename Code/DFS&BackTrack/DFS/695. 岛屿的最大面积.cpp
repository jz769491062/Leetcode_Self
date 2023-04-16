class Solution {
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        int ret = 1;
        grid[x][y] = 0;
        for (vector<int>& d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (inArea(m, n, nx, ny) && grid[nx][ny] == 1) {
                ret += dfs(grid, nx, ny);
            }
        }
        return ret;
    }

    bool inArea(int m, int n , int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/max-area-of-island/description/