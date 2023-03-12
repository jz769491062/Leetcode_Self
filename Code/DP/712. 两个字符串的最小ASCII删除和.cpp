class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 注意初始化带上[m][n]
        for (int i = 1; i <= m; i++) {
            // 注意这里的string也是索引-1的
            dp[i][0] = (int)s1[i - 1] + (int)dp[i - 1][0];
        }
        for (int i = 1; i <= n; i++) {
            // 注意这里的string也是索引-1的
            dp[0][i] = (int)s2[i - 1] + (int)dp[0][i - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 注意text索引- 1
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 删哪个就把哪个的ASCII值也给加上
                    dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                }
            }
        }
        return dp[m][n];
    }
};// https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/