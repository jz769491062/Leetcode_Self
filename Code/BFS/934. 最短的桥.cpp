class Solution {
    int n;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<pair<int, int>> island;
    queue<pair<int, int>> q;
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // 只有两个岛
        // 找到一个岛后，沿着岛的边缘BFS，摸到另一个岛就停下，然后输出搜索的深度
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
            }
        }
        return 0;
    }

    int bfs(vector<vector<int>>& grid, int x, int y) {
        q.push({x, y});
        grid[x][y] = -1;
        // 找到一个岛，标记为-1
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (vector<int>& di : dir) {
                int nx = cx + di[0];
                int ny = cy + di[1];
                island.push_back({nx, ny});
                if (inArea(nx, ny) && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        // 然后从岛的边缘逐层BFS找答案
        int res = 1;
        for (pair<int, int>& p : island) {
            q.push(p);
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0 ; i < sz; i++) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                for (vector<int>& di: dir) {
                    int nx = cx + di[0];
                    int ny = cy + di[1];
                    if (!inArea(nx, ny)) {
                        continue;
                    }
                    if (grid[nx][ny] == -1) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        return res;
                    }
                    if (grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
            }
            res++;
        }
        return 0;
    }

    bool inArea(int x, int y) {
        return x >=0 && x < n && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/shortest-bridge/description/