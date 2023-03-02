class Solution {
    vector<vector<bool>> visited;
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return;
        }
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            dfs(grid, x + 1, y);
            dfs(grid, x - 1, y);
            dfs(grid, x, y + 1);
            dfs(grid, x, y - 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        visited.resize(grid.size(), vector<bool>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};// https://leetcode.cn/problems/number-of-islands/description/