class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 本题k固定为2，使用[1][2]作为dp循环部分，[0]是base case和避免j-1负数索引
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
            }
        }
        // 交易次数从1开始算，为了处理-1的情况,也就是dp[i][0][0]和dp[i][0][1]其实只是初始化base case，并不参与循环
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 2; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][2][0];
    }
}; // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/