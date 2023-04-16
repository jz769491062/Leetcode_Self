class Solution {
    vector<vector<int>> res;
    vector<vector<bool>> pvec, avec;
    int m, n;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        pvec.resize(m, vector<bool>(n));
        avec.resize(m, vector<bool>(n));
        for (int i = 0 ; i < m; i++) {
            dfs(heights, pvec, i, 0);
            dfs(heights, avec, i, n - 1);
        }
        for (int i = n - 1 ; i >= 1; i--) {
            dfs(heights, pvec, 0, i);
            dfs(heights, avec, m - 1, n - i - 1);
        }
        for (int i = 0 ; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (pvec[i][j] && avec[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int x, int y) {
        if (ocean[x][y]) {
            return;
        }
        ocean[x][y] = true;
        for (vector<int>& di: dir) {
            int nx = x + di[0], ny = y + di[1];
            if (inArea(nx, ny) && heights[nx][ny] >= heights[x][y]) {
                dfs(heights, ocean, nx, ny);
            }
        }
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
};// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/