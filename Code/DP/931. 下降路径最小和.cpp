class Solution {
    vector<vector<int>> memo;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size();
        memo = vector(n, vector<int>(n, 66666));
        for (int i = 0; i < n; i++) {
            res = min(res, DP(matrix, n - 1, i));// 最后一行找最小值，然后DP往上倒推
        }
        return res;
    }

    int DP(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        if (i < 0 || j < 0 || i >= n || j >= n) {
            return 66666;
        }
        if (memo[i][j] != 66666) {
            return memo[i][j];
        }
        if (i == 0) {
            // 第一行base case
            memo[i][j] = matrix[i][j];
            return matrix[i][j];
        }
        memo[i][j] = matrix[i][j] + min(DP(matrix, i - 1, j - 1), min(DP(matrix, i - 1, j), DP(matrix, i - 1, j +1)));
        return memo[i][j];
    }
};// https://leetcode.cn/problems/minimum-falling-path-sum/description/