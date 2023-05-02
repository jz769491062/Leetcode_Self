class Solution {// https://leetcode.cn/problems/Db3wC1/description/?company_slug=huawei
    int dx[5] = {0, 1, 0,  -1, 0};
    int dy[5] = {1, 0, -1, 0, 0};
    int m, n; // m row n col
    int max_step;
    bool visited[55][55][105][2][2] = {false};
public:
    bool dfs(int x, int y, int step, bool magic1, bool magic2, const vector<vector<string>>& maze) {
        if (visited[x][y][step][magic1][magic2]) {
            return false; // 死胡同
        }
        visited[x][y][step][magic1][magic2] = true;
        if (x == m - 1 && y == n - 1) {
            return true; // 到达终点
        }
        if (step == max_step) {
            return false; // 步数够走遍全图了还没走出去，false
        }
        if (max_step - step < m - 1 - x + n - 1 - y) {
            return false; // 剪枝，离终点太远但所剩步数太少的情况
        }
        for (int i = 0; i < 5; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inArea(nx, ny)) {
                if (maze[step + 1][nx][ny] == '.') {
                    // 空地
                    if (dfs(nx, ny, step + 1, magic1, magic2, maze)) {
                        return true;
                    }
                } else {
                    // 陷阱地，考虑使用卷轴
                    if (!magic1) {
                        if (dfs(nx, ny, step + 1, true, magic2, maze)) {
                            return true;
                        }
                    }
                    if (!magic2) {
                        // 永久卷轴，后续步骤都把magic2设true
                        for (int j = step + 1; j <= max_step; j++) {
                            if (dfs(nx, ny, j, magic1, true, maze)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool escapeMaze(vector<vector<string>>& maze) {
        m = maze[0].size();
        n = maze[0][0].size();
        max_step = maze.size() - 1;
        return dfs(0, 0, 0, false, false, maze);
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/Db3wC1/description/?company_slug=huawei