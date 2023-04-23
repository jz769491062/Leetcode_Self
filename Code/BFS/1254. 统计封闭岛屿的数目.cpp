class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
public:
    void bfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            if (grid[cx][cy] == 0) {
                grid[cx][cy] = 1;
                for (vector<int>& di : dir) {
                    int nx = cx + di[0];
                    int ny = cy + di[1];
                    if (inArea(nx, ny, m, n) && !visited[nx][ny] && grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    bool inArea(int cx, int cy, int m, int n) {
        return !(cx < 0 || cx >= m || cy < 0 || cy >= n);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n));
        // 淹掉上下
        for (int i = 0; i < n;i++) {
            bfs(grid, 0, i);
            bfs(grid, m - 1, i);
        }
        // 淹掉左右
        for (int i = 0; i < m;i++) {
            bfs(grid, i, 0);
            bfs(grid, i, n - 1);
        }
        // 统计剩余岛屿数量即可
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};