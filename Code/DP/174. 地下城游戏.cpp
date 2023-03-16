class Solution {
    vector<vector<int>> memo;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        memo.resize(m, vector<int>(n, -1));
        // 「从 A 到达右下角的最少生命值」应该由「从 B 到达右下角的最少生命值」和「从 C 到达右下角的最少生命值」推导出来
        return DP(dungeon, 0, 0);
    }

    int DP(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 &&j == n - 1) {
            // 骑士落地不死
            return grid[i][j] >= 0 ? 1 : -grid[i][j] + 1;
        }
        if (i == m || j == n) {
            return INT_MAX;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        // 注意用负的grid[i][j]表示需要几点血量
        int res = -grid[i][j] + min(DP(grid, i + 1, j), DP(grid, i, j + 1));
        // 注意有血瓶时，也要保证至少1点生命
        memo[i][j] = res <= 0 ? 1 : res;
        return memo[i][j];
    }
};// https://leetcode.cn/problems/dungeon-game/description/