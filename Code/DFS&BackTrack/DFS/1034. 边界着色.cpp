class Solution {
    vector<vector<int>> res, ans;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size(), n = grid[0].size();
        ans.resize(m, vector<int>(n, 0));
        // 根据grid，把颜色上给ans
        dfs(grid, row, col, color);
        // 先跑完dfs再上剩余块的色，这样刚上色的色块不会迷惑dfs逻辑
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 0) {
                    ans[i][j] = grid[i][j];
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int color) {
        int count = 0;// 四周多少个同色的，都是同色说明不是边界
        for (int* di : dir) {
            int nx = x + di[0], ny = y + di[1];
            if (!inArea(nx, ny)) continue;
            if (grid[x][y] != grid[nx][ny]) continue;
            else count++;
            // visited
            if (ans[nx][ny] != 0) continue;
            ans[nx][ny] = -1; // mark visited
            dfs(grid, nx, ny, color);
        }
        // 不是边界就照抄，是边界就上色
        ans[x][y] = count == 4 ? grid[x][y] : color;
    }

    bool inArea(int x, int y) {
        return x >= 0 &&x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/coloring-a-border/description/