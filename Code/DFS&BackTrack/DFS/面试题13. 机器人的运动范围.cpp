class Solution {
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited;
    int res = 1;
    int m, n, k;
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        visited.resize(m, vector<bool>(n));
        dfs(0, 0);
        return res;
    }

    void dfs(int x, int y) {
        visited[x][y] = true;
        for (vector<int>& di : dir) {
            int nx = x + di[0];
            int ny = y + di[1];
            if (CanReach(nx, ny) && !visited[nx][ny]) {
                res++;
                dfs(nx, ny);
            }
        }
    }

    bool CanReach(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        int sum = 0;
        while (x > 0 || y > 0) {
            sum += x % 10;
            x /= 10;
            sum += y % 10;
            y /= 10;
        }
        if (sum > k) {
            return false;
        }
        return true;
    }
};// https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/