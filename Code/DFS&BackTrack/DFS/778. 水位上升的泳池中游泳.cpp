class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int m;
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        // 注意下界是grid[0][0]不是0
        int left = grid[0][0], right = m * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            visited.clear();
            visited.resize(m, vector<bool>(m));    
            if (dfs(grid, mid, 0, 0)) {
                // 如果有可能使用更少的精力，那就降低体力
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool dfs(vector<vector<int>>& heights, int time, int x, int y) {
        if (x == m - 1 && y == m - 1) {
            return true;
        }
        visited[x][y] = true;
        for (vector<int>& di : dir) {
            int nx = x + di[0], ny = y + di[1];
            if (!inArea(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            // 注意不要因为time不够就提前return, 还有别的方向没搜索完成呢
            if (heights[nx][ny] > time) {
                continue;
            }
            // 有一条能走通就OK
            if (dfs(heights, time, nx, ny)) {
                return true;
            }
        }
        return false;
    }

    bool inArea(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= m) {
            return false;
        }
        return true;
    }
};// https://leetcode.cn/problems/swim-in-rising-water/description/