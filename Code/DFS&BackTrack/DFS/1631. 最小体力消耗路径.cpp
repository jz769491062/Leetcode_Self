class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int m, n;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        int left = 0, right = pow(10, 6);
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            visited.clear();
            visited.resize(m, vector<bool>(n));    
            if (dfs(heights, mid, 0, 0)) {
                right = mid - 1;
                res = mid;
            } else {
                // 如果有可能使用更少的精力，那就降低体力
                left = mid + 1;
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& heights, int stamina, int x, int y) {
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        visited[x][y] = true;
        for (vector<int>& di : dir) {
            int nx = x + di[0], ny = y + di[1];
            if (!inArea(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            // 注意不要因为stamina不够就提前return, 还有别的方向没搜索完成呢
            if (abs(heights[nx][ny] - heights[x][y]) > stamina) {
                continue;
            }
            // 有一条能走通就OK
            if (dfs(heights, stamina, nx, ny)) {
                return true;
            }
        }
        return false;
    }

    bool inArea(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }
        return true;
    }
};// https://leetcode.cn/problems/path-with-minimum-effort/description/