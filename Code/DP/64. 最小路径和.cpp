class Solution {
    vector<vector<int>> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memo.resize(m, vector<int>(n, -1));
        // 也可以从终点倒推，也方便状态转移
        return DP(grid, m - 1, n - 1);
    }

    int DP(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 &&j == 0) {
            return grid[0][0];
        }
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        memo[i][j] = grid[i][j] + min(DP(grid, i - 1, j), DP(grid, i, j - 1));
        return memo[i][j];
    }
};// https://leetcode.cn/problems/minimum-path-sum/description/