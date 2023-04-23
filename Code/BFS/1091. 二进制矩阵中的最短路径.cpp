class Solution {
    vector<vector<int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, { -1, -1}, {-1, 0}, {-1, 1}};
    vector<vector<bool>> visited;
    int n;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        visited.resize(n, vector<bool>(n));
        if (grid[0][0] != 0) {
            return -1;
        }
        return bfs(grid, 0, 0);
    }

    int bfs(vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        int dist = 1;
        while (!q.empty()) {
            int sz = q.size();
            // 遍历该距离所有的节点，之后再更新距离
            for (int i = 0; i < sz; i++) {
                int currX = q.front().first, currY = q.front().second;
                q.pop();
                if (currX == n - 1 && currY == n - 1) {
                    // 因为BFS的特性，可以直接return
                    return dist;
                }
                for (vector<int>& di : dir) {
                    int nx = currX + di[0], ny = currY + di[1];
                    if (inArea(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
            // 注意更新距离的时机
            dist++;
        }
        return -1;
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
};// https://leetcode.cn/problems/shortest-path-in-binary-matrix/description/