class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n));
        
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        vector<pair<int, int>> borderVec;
        int startColor = grid[row][col];
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            int curr = grid[r][c];
            q.pop();
            bool isBorder = false;
            for (vector<int>& di : dir) {
                int nx = r + di[0];
                int ny = c + di[1];
                if (!inArea(nx, ny, m, n) || grid[nx][ny] != startColor) {
                    isBorder = true; // 说明r, c是border
                } else if (!visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            if (isBorder) {
                borderVec.push_back({r, c});
            }
        }
        for (pair<int, int>& p : borderVec) {
            grid[p.first][p.second] = color;
        }
        return grid;
    }

    bool inArea(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/coloring-a-border/description/