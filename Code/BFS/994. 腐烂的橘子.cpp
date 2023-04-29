// https://leetcode.cn/problems/rotting-oranges/description/
class Solution {
    bool inArea(int i, int j, int rows, int cols) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<vector<int>> q; // 每个队列的元素代表接下来要搜索的橘子的坐标
        vector<vector<bool>> visited(m, vector<bool>(n));
        int freshCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        // 注意题意，没新鲜橘子的时候step就是0
        int step = 0;
        while (!q.empty()) {
            // 没有新鲜橘子了，可以不用继续搜索
            if (freshCount == 0) {
                break;
            }
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                vector<int> curr = q.front();
                q.pop();
                int x = curr[0], y = curr[1];
                for (vector<int>& di : dir) {
                    int nx = x + di[0], ny = y + di[1];
                    if (inArea(nx, ny, m, n) && !visited[nx][ny] && grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        freshCount--;
                    }
                }

            }
        }
        // 还有剩下橘子的好橘子
        if (freshCount > 0) {
            return -1;
        }
        return step;
    }
};