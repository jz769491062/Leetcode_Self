class Solution {
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited;
    int m, n;
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        int left = 0;
        // 路径值不可能超过这个值
        int right = min(grid[0][0], grid[m - 1][n - 1]);
        // 对可能的路径数值进行二分搜索
        while (left <= right) {
            int mid = left + (right - left) / 2;
            visited.clear();
            visited.resize(m, vector<bool>(n));
            // dfs结果表示：是否有一条路径，值大于等于mid?
            if (dfs(grid, mid, 0, 0)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

    bool dfs(vector<vector<int>>& grid, int minNum, int x, int y) {
        // 找到了一条大于等于minNum的路径，true
        if (x == m - 1 && y == n - 1) return true;
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        if (visited[x][y]) return false;
        visited[x][y] = true;
        // 当前路径比minNum还要小，我们的目标路径分数需要降低，false
        if (grid[x][y] < minNum) return false;
        bool res = false;
        for (vector<int>& di : dir) {
            if (dfs(grid, minNum, x + di[0], y +di[1])) {
                res = true;
            }
        }
        return res;
    }
};