class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[i] - fee; // 初始化也要带上手续费
        }
        // 处理起始base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee; // 注意手续费
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 和122区别在手续费
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]- fee);
        }
        return dp[n - 1][0];
    }
};// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/